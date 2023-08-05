import math

def calculate_prefix_xor(a, n):
    prefixXOR = [0] * (n + 1)
    for i in range(1, n + 1):
        prefixXOR[i] = prefixXOR[i - 1] ^ a[i - 1]
    return prefixXOR

def count_subarrays_with_even_divisors(prefixXOR, n):
    count = {}
    for xor_value in prefixXOR:
        count[xor_value] = count.get(xor_value, 0) + 1

    for xor_value in count:
        if xor_value == 0 or int(math.sqrt(xor_value)) ** 2 == xor_value:
            count[xor_value] = 0

    total_subarrays = n * (n + 1) // 2
    for xor_value in count:
        total_subarrays -= count[xor_value]

    return total_subarrays

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))

        prefixXOR = calculate_prefix_xor(a, n)
        answer = count_subarrays_with_even_divisors(prefixXOR, n)

        print(answer)
