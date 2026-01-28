# Base class
class Square:
    def __init__(self, side=0):
        self.side = side
        print("Square constructor called")

    def getPeri(self):
        return 4 * self.side

    def getArea(self):
        return self.side * self.side

    def __del__(self):
        print("Square destructor called")


# Derived class
class Cube(Square):
    def __init__(self, side=0):
        super().__init__(side)
        print("Cube constructor called")

    # Overrides Square.getArea
    def getArea(self):
        return 6 * self.side * self.side

    def getVolume(self):
        return self.side ** 3

    def __del__(self):
        print("Cube destructor called")
        super().__del__()


# Main program
if __name__ == "__main__":
    sq = Square(4)
    print("Square Perimeter:", sq.getPeri())
    print("Square Area:", sq.getArea())

    print()

    cb = Cube(3)
    print("Cube Surface Area:", cb.getArea())
    print("Cube Volume:", cb.getVolume())
