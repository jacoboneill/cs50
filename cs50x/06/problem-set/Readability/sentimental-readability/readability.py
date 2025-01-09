import re


def main():
    text = input("Text: ")
    print(format(coleman_liau(text)))


def coleman_liau(text):
    letters = float(len(re.findall(r"[A-Za-z]", text)))
    words = float(len(re.findall(r" ", text)) + 1)
    sentences = float(len(re.findall(r"[!?.]", text)))

    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8

    return round(index)


def format(index):
    if index < 1:
        return "Before Grade 1"
    elif index > 16:
        return "Grade 16+"
    else:
        return f"Grade {index}"


main()
