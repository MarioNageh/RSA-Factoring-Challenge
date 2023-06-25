#!/usr/bin/python3

def get_factors(n):
    i = 2
    for _ in range(n):
        if n % i == 0:
            return f"{n}={n//i}*{i}"
        i += 1


def main():
    # Your Python script code here
    # sys.argv[1] = "env"
    arg = sys.argv[1]
    filename = arg  # Replace with your file name

    with open(filename, "r") as file:
        for line in file:
            i = int(line)
            print(get_factors(i))


if __name__ == "__main__":
    main()
