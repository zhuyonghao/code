# student = {"name": "小明", "gender": "男", "age": 18}
# print(student)
# print(student["name"])
# print(student["gender"])
# print(student["age"])
# print(f"student is {student["name"]}!")

# student["class"] = 19
# print(student)
# student["class"] = 16
# print(student)
# del student["class"]
# print(student)

# sports = {
#     "g": "basketball",
#     "a": "football",
#     "b": "run",
#     "c": "basketball",
#     "d": "tenis"
# }
# Value = sports.get("d", "empty")
# print(Value)

# print(sports.items())
# for name, value in sports.items():
#     print(f"{name} like {value}!")
# print(sports.keys())

# friend = ["李四", "陈"]
# for name in sports.keys():
#     print(f"Hello! {name}")

#     if name in friend:
#         print(f"play with me! {name}")
# for name in sorted(sports.keys()):
#     print(name)

# for value in set(sports.values()):
#     print(value)

# aliens = []

# for alien_number in range(30):
#     new_alien = {
#         "color": "green",
#         "point": 5,
#         "speed": "slow"
#     }
#     aliens.append(new_alien)

# for alien in aliens[:5]:
#     print(alien)

# print(f"create {len(aliens)}!")

# pizza = {
#     "crust": "thick",
#     "toppings": ["mushroom", "extra cheese"]
# }

# print(f"pizza {pizza["crust"]}!")

# for topping in pizza["toppings"]:
#     print(topping)

# sports = {
#     "g": ["basketball", "football"],
#     "a": ["football", "tennis", "basketball"],
#     "b": ["run"],
#     "c": ["basketball", "tennis"]
# }

# for name, sport in sports.items():
#     print(f"hello {name}")

#     for s in sport:
#         print(s)

user = {
    "oliver": {
        "first": "oliver",
        "last": "allen",
        "location": "uk"
    },
    "David": {
        "first": "david",
        "last": "smith",
        "location": "us"
    }
}

for name, message in user.items():
    print(f"{name}'s message: ")
    for key, value in message.items():
        print(f"{key}: {value}")