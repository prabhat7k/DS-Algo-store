def is_prime(n: int) -> bool:
    """Return True if n is a prime number."""
    if n <= 1:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


if __name__ == "__main__":
    num = int(input("Enter a number: "))
    print(f"{num} is prime!" if is_prime(num) else f"{num} is not prime.")
