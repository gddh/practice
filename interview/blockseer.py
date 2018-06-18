def is_safe(x, y):
    '''
    Ensures x and y values are within bounds and not the
    indices of * or #
    '''

    return ((x < 3 and x >= 0 and y < 4 and y >= 0) and
            not (x == 0 and y == 3) and not (x == 2 and y == 3))  

def moved_horizontal(x, y, res):
    '''
    After moving horizontally, check if the vertical movement
    from the x and y coordinate is safe.
    If safe, append to the result list.
    '''
    if is_safe(x, y + 1):
        res.append((x, y + 1))
    if is_safe(x, y - 1):
        res.append((x, y - 1))

def moved_vertical(x, y, res):
    '''
    After moving horizontally, check if the horizontal movement
    from the x and y coordinate is safe.
    If safe, append to the result list.
    '''
    if is_safe(x + 1, y): 
        res.append((x + 1, y))
    if is_safe(x - 1, y):
        res.append((x - 1, y))

def n_steps(point, n):
    '''
    Arguments:
        point - a list represented as [x-coord, y-coord]
        n - step size
    Description:
        Checks to see if up, down, left, right are valid
        movements. If so add to res.
    Return Value:
        res - a list of all of the possible movements.
    '''
    res = []
    if is_safe(point[0] + n, point[1]):
        moved_horizontal(point[0] + n, point[1], res)
    if is_safe(point[0] - n, point[1]):
        moved_horizontal(point[0] - n, point[1], res)
    if is_safe(point[0], point[1] + n):
        moved_vertical(point[0], point[1] + n, res)
    if is_safe(point[0], point[1] - n):
        moved_vertical(point[0], point[1] - n, res)
    return res

def l_step(coordLst, keypad, step_size):
    '''
    Arguments:
        coordLst - dictionary mapping qualifying i-digit numbers 
        to coordinates that's been calculated up to the ith iteration.
        keypad - 2D array representation of a phone keypad
        n - target nth digit
    Description:
       for each i_digit_number calculated so far, step by step_size
       to get the new points. for each new point, add entry to a new
       coordLst.
    Return Value:
        return a dictionary mapping i-digit numbers to coordinates
        calculated in this iteration.
    '''
    new_coordLst = {}
    for i_digit_num in coordLst.keys():
        new_points = n_steps(coordLst[i_digit_num], step_size)
        if new_points != []:
            for new_point in new_points:
                digit = keypad[new_point[1]][new_point[0]]
                new_coordLst[i_digit_num + digit] = new_point
    return new_coordLst


def telephone_keypad(n):
    '''
    Arguments:
        n - target nth digit.
    Description:
        prints the qualifying numbers followed by the 
        number of qualifying numbers. 
        First checks that n is greater than 0. 
        Then iterates n - 1 time. Every third iteration, move a
        tall L. On other iterations, move a short L.
        coordLst tracks coordinates and qualifying i-digit
        numbers that's been calculated up to the ith iteration.
    '''
    if (n < 1):
        print "number must be greater than 0"
        return
    keypad =[['1','2','3'],
             ['4','5','6'],
             ['7','8','9'],
             ['*','0','#']]
    i = 0
    coordLst = {'0':(1, 3)}
    while (i < n - 1):
        if (i % 3 == 0):
            coordLst = l_step(coordLst, keypad, 2)
        else:
            coordLst = l_step(coordLst, keypad, 1)
        i = i + 1
    print "qualifying numbers is: ", coordLst.keys()
    print "number of qualifying numbers: ", len(coordLst.keys())

if __name__ == "__main__":
    print "Please enter n, greater than 0"
    n = int(raw_input())
    print "-------------------------------------"
    telephone_keypad(n)
