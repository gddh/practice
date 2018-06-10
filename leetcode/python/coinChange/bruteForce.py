def coinChangeHelper(coins, amount):
    if (amount < 0 or not coins):
        return -1
    if (amount == 0):
        return 0 
    for coin in coins:
        if (coin <= amount):
            rv = coinChangeHelper(coins, amount - coin)
            if rv >= 0:
                return rv + 1
    return -1

def coinChange(coins, amount):
    coins.sort(reverse=True);
    print "coins: ", coins, " amount ", amount
    return coinChangeHelper(coins, amount)

def test(coins, amount):
    print(coinChange(coins, amount))

if __name__ == "__main__":
    #test([1,2,5], 11)
    #test([2],3)
    #test([5, 2, 7, 9], 81)
    test([186,419,83,408], 6249)
