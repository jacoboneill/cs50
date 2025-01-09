#include <cs50.h>
#include <stdio.h>

bool isAmericanExpress(long card_number)
{
    bool case_a = card_number >= 340000000000000 && card_number < 350000000000000;
    bool case_b = card_number >= 370000000000000 && card_number < 380000000000000;

    return case_a || case_b;
}

bool isMasterCard(long card_number)
{
    return card_number >= 5100000000000000 && card_number < 5600000000000000;
}

bool _isVisa13(long card_number)
{
    return card_number >= 4000000000000 && card_number < 5000000000000;
}

bool _isVisa16(long card_number)
{
    return card_number >= 4000000000000000 && card_number < 5000000000000000;
}

bool isVisa(long card_number)
{
    return _isVisa13(card_number) || _isVisa16(card_number);
}

long get_card_number(string message)
{
    return get_long("%s", message);
}

bool luhns_algorithm(long card_number)
{
    // init
    int sum = 0;
    bool multiply = false;

    while (card_number > 0)
    {
        int result = card_number % 10;
        if (multiply)
        {
            result *= 2;
            if (result >= 10)
            {
                sum += 1 + (result % 10);
            }
            else
            {
                sum += result;
            }
        }
        else
        {
            sum += result;
        }

        card_number /= 10;
        multiply = !multiply;
    }
    return sum % 10 == 0;
}

bool validate(int luhns_number)
{
    return luhns_number % 10 == 0;
}

int main()
{
    long card_number = get_card_number("Number: ");
    if (!(isAmericanExpress(card_number) || isMasterCard(card_number) || isVisa(card_number)))
    {
        printf("INVALID\n");
    }
    else
    {
        bool isValid = luhns_algorithm(card_number);
        if (!isValid)
        {
            printf("INVALID\n");
        }
        else
        {
            if (isAmericanExpress(card_number))
            {
                printf("AMEX\n");
            }
            else if (isMasterCard(card_number))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("VISA\n");
            }
        }
    }
}
