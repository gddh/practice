'''
:type magic_number: int 
:type numbers: list[int]
:type rtype: bool
'''
def arithmetic_boggle(magic_number, numbers):
    if magic_number == 0 and numbers == []:
        return True
    if numbers == []:
        return False
    return (arithmetic_boggle(magic_number - numbers[0], numbers[1:]) or
            arithmetic_boggle(magic_number + numbers[0], numbers[1:]))


if __name__ == "__main__":
    print(arithmetic_boggle(10,[1,2]))
    print(arithmetic_boggle(2,[1,2,3,4]))
    print(arithmetic_boggle(0,[]))
    print(arithmetic_boggle(1,[]))
    print(arithmetic_boggle(1,[1]))
    print(arithmetic_boggle(0,[1]))
