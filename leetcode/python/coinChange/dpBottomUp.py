def coinChange(coins, amount):
    lst = [amount + 1] * (amount + 1)
    lst[0] = 0
    for i in range(amount):
        i = i + 1
        for coin in coins:
            if (coin <= i):
                lst[i] = min(lst[i - coin] + 1, lst[i])
    return lst[amount] if lst[amount] <= amount else -1

def test(coins, amt):
    print(coinChange(coins, amt))

if __name__ == "__main__":
    test([1,2,5], 11)
    test([2], 3)
    test([186,419,83,408], 6249)
