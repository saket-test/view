# TODO


def get_input():
    try:
        card = int(input("Number: "))
    except:
        card = get_input()
    return card


def main():
    card = get_input()
    length = 0
    y = card
    while y > 1:
        y /= 10
        length += 1
    if length != 13 and length != 15 and length != 16:
        print("INVALID\n")
        return 1
    y = card
    for i in range(length - 2):
        y //= 10
    first_two_digits = y
    y //= 10
    first_digit = y
    # print(f"first_two_digits: {first_two_digits}\nfirst_digit: {first_digit}")
    sum_doubles = 0
    sum_singles = 0

    i = 0
    while card >= 1:
        if i % 2 == 1:
            digit_double = (card % 10) * 2
            if digit_double < 10:
                sum_doubles += digit_double
            else:
                digit_double_sum = 0
                while digit_double >= 1:
                    digit_double_sum += digit_double % 10
                    digit_double //= 10
                sum_doubles += digit_double_sum
        elif i % 2 == 0:
            sum_singles += card % 10
        card //= 10
        i += 1

    total_sum = sum_doubles + sum_singles
    # print(f"total_sum: {total_sum}\nsum_doubles: {sum_doubles}\nsum_singles: {sum_singles}")
    if total_sum % 10 == 0:
        if length == 15 and (first_two_digits == 34 or first_two_digits == 37):
            print("AMEX\n")
        elif length == 16 and (first_two_digits < 56 and first_two_digits > 50):
            print("MASTERCARD\n")
        elif (length == 13 or length == 16) and first_digit == 4:
            print("VISA\n")
        else:
            print("INVALID\n")
            return 1
    else:
        print("INVALID\n")
        return 1


if __name__ == "__main__":
    main()
