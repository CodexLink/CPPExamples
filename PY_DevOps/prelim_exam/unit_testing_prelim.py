import unittest

class Temperature:
    def __init__(self, kelvin=None, celsius=None, fahrenheit=None):
        values = [x for x in [kelvin, celsius, fahrenheit] if x]

        if len(values) < 1:
            raise ValueError("Need argument")

        if len(values) > 1:
            raise ValueError("Only one argument")

        if celsius is not None:
            self.kelvin = celsius + 273.15

        elif fahrenheit is not None:
            self.kelvin = (fahrenheit - 32) * 5 / 9 + 273.15

        else:
            self.kelvin = kelvin

        if self.kelvin < 0:
            raise ValueError("Temperature in Kelvin cannot be negative.")

    def __str__(self):
        return f"Temperature = {self.kelvin} Kelvins"

class TemperatureTestCase(unittest.TestCase):
    # Test Case 1
    def test_no_specific_parameter_test(self):
        supplied = 100
        a = Temperature(supplied)
        self.assertEqual(a.kelvin, supplied) # The supplied value must be the same here.

        print(f"Assert #1 | Should be the same as self.kelvin: {a} == {supplied}")

    # Test Case 2
    def test_class_ctx_str_test(self):
        a = Temperature(300)
        b = Temperature(300)
        self.assertEqual(a.__str__(), b.__str__())

        print(f"Assert #2 | Double-Check Assert 2 Instances : {a} | {b}")

    # Test Case 3
    def test_assert_celcius_from_fahrenheit(self):
        supplied = 136
        expected = 330 # Type casted to int.

        a = Temperature(fahrenheit=supplied)
        self.assertEqual(int(a.kelvin), expected)

        print(f"Assert #3 | Given Fahrenheit to Kelvin should be {expected} == {int(a.kelvin)}")

    # Test Case 4
    def test_assert_celcius_from_kelvin(self):
        current_param = 43
        expected = 316.15
        a = Temperature(celsius=current_param) # Kelvins of 43 Celcius must be 316.15.
        self.assertEqual(a.kelvin, expected)

        print(f"Assert #4 | Celcius after conversion should be the following: {a.kelvin} | {expected}")

if __name__ == "__main__":
    unittest.main()


