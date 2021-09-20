import unittest

def fun(x):
    return x + 1

class myTest(unittest.TestCase):
    def test(self):
        self.assertEqual(fun(4), 5)


if __name__ == "__main__":
    unittest.main()
