def fib(num, mem):
    if num <= 2:
        return 1
    if num in mem:
        return mem[num]
    mem[num] = fib(num - 1, mem) + fib(num - 2, mem)
    return mem[num]


def main():
    cases = int(input())
    numbers = [int(input()) for _ in range(cases)]

    mem = {}

    for i in range(cases):
        print(fib(fib(numbers[i], mem), mem))


if __name__ == "__main__":
    main()
