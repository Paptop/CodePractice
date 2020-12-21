class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.categories = [big, medium, small]
        

    def addCar(self, carType: int) -> bool:
        cars = self.categories[carType - 1]
        
        if cars == 0:
            return False
        else:
            self.categories[carType - 1] -= 1
            return True
        
        
