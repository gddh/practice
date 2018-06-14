def countBits(num):
    return [bin(n)[2:].count("1") for n in range(num + 1)]

if __name__ == "__main__":
    print(countBits(5))
