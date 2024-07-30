-- Get Crime Scene Report of stolen CS50 Duck
SELECT * FROM crime_scene_reports csr WHERE description LIKE '%duck%'

-- OUTPUT
-- id |year|month|day|street         |description                                                                                                                                                                                                             |
-- ---+----+-----+---+---------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
-- 295|2023|    7| 28|Humphrey Street|Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.|

-- Get transcripts:
SELECT * FROM interviews i WHERE transcript LIKE '%bakery%' AND month = 7;

-- id |name   |year|month|day|transcript                                                                                                                                                                                                                                                                                                          |
-- ---+-------+----+-----+---+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
-- 161|Ruth   |2023|    7| 28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- 162|Eugene |2023|    7| 28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- 163|Raymond|2023|    7| 28||As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.|

-- What we learned
-- - Ruth says that they saw a car leave the scene and security should have picked it up
-- - Eugene said they recognized them
-- - Eugene says the name of the bakery is Emma's bakery, name of owner or name of business?
-- - Eugene says before the crime the thief took money out at an ATM on Leggett Street
-- - Raymond says that the thief called someone for less than a minute.
-- - Raymond says that thief was to take earliest flight out tomorrow (29/7), acompolice booked the tickets 


-- Searching for the car.
-- Date and Time: 28 / 7 / 2023 10:15

SELECT
	bsl.minute,
	bsl.license_plate
FROM
	bakery_security_logs bsl
WHERE
	bsl.year = 2023
	AND bsl.month = 7
	AND bsl.day = 28
	AND bsl.hour = 10
	AND bsl.minute >= 10
	AND bsl.minute <= 20
	AND bsl.activity = 'exit'

-- This gives us a ± 5 minute window for the leaving of the thief. These are the times and number plates from this window:
-- 
-- minute|license_plate|
-- ------+-------------+
--     16|5P2BI95      |
--     18|94KL13X      |
--     18|6P58WS2      |
--     19|4328GD8      |
--     20|G412CB7      |

-- We can then further find all the people that have these license plates, their names, numbers, passport numbers, and bank details via:

WITH suspects AS (
SELECT
	p.*,
	ba.account_number AS bank_account_number,
	ba.creation_year
FROM people p
JOIN bakery_security_logs bsl ON bsl.license_plate = p.license_plate
JOIN bank_accounts ba ON p.id = ba.person_id
WHERE
	bsl.year = 2023
	AND bsl.month = 7
	AND bsl.day = 28
	AND bsl.hour = 10
	AND bsl.minute BETWEEN 10 AND 20
	AND bsl.activity = 'exit'
)

SELECT * FROM suspects;

-- id    |name |phone_number  |passport_number|license_plate|bank_account_number|creation_year|
-- ------+-----+--------------+---------------+-------------+-------------------+-------------+
-- 686048|Bruce|(367) 555-5533|     5773159633|94KL13X      |           49610011|         2010|
-- 467400|Luca |(389) 555-5198|     8496433585|4328GD8      |           28500762|         2014|
-- 243696|Barry|(301) 555-4174|     7526138472|6P58WS2      |           56171033|         2018|
-- 
-- So we now have 3 suspects (2 filtered away becuase they don't have bank records) of Bruce, Luca, and Barry

-- To make our suspects more customisable, I am going to make it so the id's are hardcoded:

WITH suspects AS (
SELECT
  p.*,
  ba.account_number AS bank_account_number
FROM people p
JOIN bank_accounts ba ON p.id = ba.person_id
WHERE
  p.id IN (686048, 467400, 243696)
)

SELECT * FROM suspects;

-- We now get the same results as before.

Now if I filter the transactions on 'Leggett Street' with these bank numbers I get the following:

WITH suspects AS (
SELECT
  p.*,
  ba.account_number AS bank_account_number
FROM people p
JOIN bank_accounts ba ON p.id = ba.person_id
WHERE
  p.id IN (686048, 467400, 243696)
)

 SELECT
	s.*,
	at2.transaction_type,
	at2.amount
FROM
	suspects s
JOIN atm_transactions at2 ON
	s.bank_account_number = at2.account_number
WHERE
	at2.year = 2023
	AND at2.month = 7
	AND at2.day = 28
	AND at2.atm_location = 'Leggett Street'

-- I get the following:

-- id    |name |phone_number  |passport_number|license_plate|bank_account_number|transaction_type|amount|
-- ------+-----+--------------+---------------+-------------+-------------------+----------------+------+
-- 467400|Luca |(389) 555-5198|     8496433585|4328GD8      |           28500762|withdraw        |    48|
-- 686048|Bruce|(367) 555-5533|     5773159633|94KL13X      |           49610011|withdraw        |    50|

-- We can conclude that Barry is no longer a suspect:

WITH suspects AS (
SELECT
  p.*,
  ba.account_number AS bank_account_number
FROM people p
JOIN bank_accounts ba ON p.id = ba.person_id
WHERE
  p.id IN (686048, 467400)
)

-- The less than a minute phone number:

We can now look to see who Luca and Bruce called on 28/7/2023 for less than a minute with:

WITH suspects AS (
SELECT
  p.*,
  ba.account_number AS bank_account_number
FROM people p
JOIN bank_accounts ba ON p.id = ba.person_id
WHERE
  p.id IN (686048, 467400)
)

SELECT
	s.name
FROM
	suspects s
JOIN phone_calls pc ON
	s.phone_number = pc.caller
WHERE
	pc.year = 2023
	AND pc.month = 7
	AND pc.day = 28
	AND pc.duration < 60

-- The table shows one person:

-- name |
-- -----+
-- Bruce|

-- This therefore means that Bruce is our theif. We can see that Bruce has a flight on 29/7/2023 at 8:20 am going to LaGuardia Airport, New York from Fiftyville Regional Airport, Fiftyville in Seat 4A:

SELECT
	CONCAT(oa.full_name, ', ', oa.city) AS origin,
	CONCAT(da.full_name, ', ', da.city) AS destination,
	f.hour,
	f.minute,
	p.seat
FROM
  flights f
  JOIN passengers p ON f.id = p.flight_id
  JOIN airports oa ON f.origin_airport_id = oa.id
  JOIN airports da ON f.destination_airport_id = da.id
WHERE
p.passport_number = ( SELECT p2.passport_number FROM people p2 WHERE p2.name = 'Bruce')

-- origin                                 |destination                     |hour|minute|seat|
-- ---------------------------------------+--------------------------------+----+------+----+
-- Fiftyville Regional Airport, Fiftyville|LaGuardia Airport, New York City|   8|    20|4A  |

-- Finally, we need to find the acompolice, this can be done by looking at bruce's phone records again on that day and see who the returning number is:

WITH bruce AS (SELECT * FROM people p JOIN bank_accounts ba ON p.id = ba.person_id WHERE p.id = 686048),
phone_call AS (SELECT * FROM phone_calls pc JOIN bruce b ON pc.caller = b.phone_number WHERE pc.year = 2023 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60)

SELECT p.* FROM people p JOIN phone_call pc ON p.phone_number = pc.receiver

-- We get:

-- id    |name |phone_number  |passport_number|license_plate|
-- ------+-----+--------------+---------------+-------------+
-- 864400|Robin|(375) 555-8161|               |4V16VO0      |

-- So, Our answers are:
-- Thief      : Bruce
-- Accomplice : Robin
-- Destination: LaGuardia Airport, New York City
