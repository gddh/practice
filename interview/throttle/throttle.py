from time import time, sleep


def throttle(timeout):
    """
    Decorator that returns  a rate limited version of the decorated function 
    that prevents the original function from executing too frequently.
    Specifically it only executes the original function at most once every `timeout` seconds.
    Args:
     timeout (float): The returned function can be called at most once every timeout seconds.
     quiet (bool): If True then silently skip running the function, otherwise raise an exception.
    Returns:
     func: Function that  is being decorated.
    """
    def real_decorator(some_function):
        start = 0
        def wrapper(*args, **kwargs):
            nonlocal start
            diff = 0
            end = time()
            diff = end - start
            if diff > timeout:
                start = time()
                some_function(*args, **kwargs)
                print("args: ", args)
                print("kwargs: ", kwargs)
        return wrapper
    return real_decorator


# ===============================================
# The following code utilizes the function above.
# ===============================================
@throttle(5)
def test_throttle(param):
    print(time(), param)


for i in range(10):
    test_throttle(param = "A")
    sleep(1) 
