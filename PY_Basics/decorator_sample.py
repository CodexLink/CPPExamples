def validate_type(f):
    def deco(*args, **kwargs):
        print(f"args > {args}, {kwargs} | ", *args, **kwargs)
        return f(*args, **kwargs)

    return deco


@validate_type
def test(filename, key):
    print(filename, key)


from secrets import token_hex

test("test.py", token_hex(32))
