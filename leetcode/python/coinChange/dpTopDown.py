max_int = 2147483647

def coinChangeHelper(coins, amount, calculated_amt):
    if amount < 0 or not coins:
        return -1
    if amount == 0:
        return 0
    if calculated_amt[amount - 1]:
        return calculated_amt[amount - 1]
    smallest = max_int
    for coin in coins:
        res = coinChangeHelper(coins, amount - coin, calculated_amt)
        if (res < smallest and res >= 0):
            smallest = res + 1
    calculated_amt[amount - 1] = smallest if smallest != max_int else -1
    return calculated_amt[amount - 1]

def coinChange(coins, amount):
    calculated_amt = [0] * amount
    return coinChangeHelper(coins, amount, calculated_amt)

def test(coins, amt):
    print(coinChange(coins, amt))

if __name__ == "__main__":
    test([1,2,5], 11)
    test([2], 3)
    test([186,419,83,408], 6249)
