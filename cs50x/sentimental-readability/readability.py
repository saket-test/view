# TODO


def main():
    text = input("Text: ")

    letter_count = count_letters(text)
    word_count = count_words(text)
    sentence_count = count_sentences(text)
    # print(f"letter_count: {letter_count}")
    # print(f"word_count: {word_count}")
    # print(f"sentence_count: {sentence_count}")

    L = letter_count * 100.0 / word_count
    S = sentence_count * 100.0 / word_count
    # print(f"L: {L}.  S: {S}")

    index = round((0.0588 * L) - (0.296 * S) - 15.8)
    # print(index)
    if index < 1:
        print("Before Grade 1")
    elif index < 17:
        print(f"Grade {index}")
    else:
        print("Grade 16+")


def count_letters(text):
    letter_per_text = 0
    length = len(text)

    for i in range(length):
        character = text[i]
        if (character >= "A" and character <= "Z") or (
            character >= "a" and character <= "z"
        ):
            letter_per_text += 1
    return letter_per_text


def count_words(text):
    word_per_text = 1
    length = len(text)
    for i in range(length):
        character = text[i]
        if character == " ":
            word_per_text += 1
    return word_per_text


def count_sentences(text):
    sentence_per_text = 0
    length = len(text)
    for i in range(length):
        character = text[i]
        if character == "!" or character == "." or character == "?":
            sentence_per_text += 1

    return sentence_per_text


if __name__ == "__main__":
    main()
