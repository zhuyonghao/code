# class Dog:
#     def __init__(self, name, age):
#         self.name = name
#         self.age = age

#     def sit(self):
#         print(f"{self.name} is now sitting.")

#     def roll_over(self):
#         print(f"{self.name} is now rolling over")

# dog1 = Dog("aaa", 8)
# dog2 = Dog("bbb", 3)

# print(dog1.name, dog1.age)
# dog1.sit()
# dog2.sit()
# dog1.roll_over()
# dog2.roll_over()

class Car:
    '''模拟汽车'''
    def __init__(self, make, model, year):
        '''初始化attribute'''
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0

    def get_descriptive_names(self):
        long_name = f"{self.make} {self.model} {self.year}"
        return long_name.title()
    
    def updata_odometer(self, odometer_reading):
        '''更新'''
        self.odometer_reading = odometer_reading

    def increment_odometer(self, miles):
        self.odometer_reading += miles
    def read_odometer(self):
        '''打印里程'''
        print(f"This car has {self.odometer_reading} miles")

    def fill_gas_tank(self):
        print(f"{self.model}")
    
# my_car = Car("audi", "a4", 2024)
# my_car.odometer_reading = 123
# my_car.updata_odometer(12333)
# my_car.increment_odometer(111)
# my_car.read_odometer()

# class ElectricCar(Car):
#     '''继承'''
#     def __init__(self, make, model, year):
#         super().__init__(make, model, year)
#         self.battery_size = 1

#     def describe_battery(self):
#         print(f"battery: {self.battery_size}")

#     def fill_gas_tank(self):
#         print("no no no")

# my_electricCar = ElectricCar("audi", "a4", 2024)
# print(my_electricCar.get_descriptive_names())
# my_electricCar.fill_gas_tank()

class Battery:
    '''模拟电池'''
    def __init__(self, battery_size=40):
        self.battery_size = battery_size

    def describe_battery(self):
        print(f"battery: {self.battery_size}")

class ElectricCar(Car):
    def __init__(self, make, model, year):
        super().__init__(make, model, year)
        self.battery = Battery()

car = ElectricCar("audi", "a4", 2024)
car.battery.describe_battery()