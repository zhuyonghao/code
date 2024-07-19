# prompt = "Welcome!"
# prompt += "\ninput your age: "
# age = int(input(prompt))
# print(f"you are {age}")
# print(age - 18)

# i = 1
# while i <= 5:
#     print(i)
#     i += 1

# message = ""
# while message != "quit":
#     message = input("I will repeat you!(enter quit to stop): ")
#     if message != "quit":
#         print(message)

# active = True
# while active:
#     message = input("I will repeat you: ")
#     if message == "quit":
#         active = False
#     else:
#         print(message)

# i = 0
# while i <= 10:
#     i += 1
#     if i % 2 == 0:
#         continue

#     print(i)

# unconfirmed_users = ["alice", "brian", "candace"]
# confirmed_users = []

# while unconfirmed_users:
#     user = unconfirmed_users.pop()
#     print(user.title())
#     confirmed_users.append(user)

# for confirmed_user in confirmed_users:
#     print(confirmed_user.title())

# numbers = [1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2]
# number = 2
# while number in numbers:
#     numbers.remove(number)
# print(numbers) 

# responses = {}

# poll_active = True

# while poll_active:
#     name = input("your name: ")
#     response = input("your response: ")
#     responses[name] = response

#     message = input("continue(yes or no): ")
#     if message == "no":
#         poll_active = False
    
# for name, response in responses.items():
#     print(f"{name} : {response}")

# def great_user(username, gender):
#     print(f"Hello! {username}是{gender}!")

# great_user(gender = "男生", username = "小明")

# def show_name(first_name, last_name, middle_name = ""):
#     if middle_name:
#         return f"{first_name} {middle_name} {last_name}".title()
#     else:
#         return f"{first_name} {last_name}".title()

# name = show_name("oliver", "allen")
# print(name)
# name = show_name("oliver", "allen", "jr")
# print(name)

# def build_person(first_name, last_name, middle_name = None):
#     person = {"first_name": first_name.title(), "last_name": last_name.title()}
#     if middle_name:
#         person["middle_name"] = middle_name.title()
#     return person

# print(build_person("olver", "allen"))
# print(build_person("olver", "allen", "jr"))

# def great(first_name, last_name):
#     return f"Hello! {first_name.title()} {last_name.title()}"

# while True:
#     first_name = input("input your first name: ")
#     if first_name == "q":
#         break
#     last_name = input("input your second name: ")
#     if last_name == "q":
#         break
#     print(great(first_name, last_name))

# def great(names):
#     for name in names:
#         msg = f"Hello! {name}"
#         print(msg)
# user_names = ["a", "b", "c", "d", "e"]
# great(user_names)

# def work(unprint_designs, completed_designs):
#     while unprint_designs:
#         design = unprint_designs.pop()
#         print(design)
#         completed_designs.append(design)

# def print_designs(completed_designs):
#     for completed_design in completed_designs:
#         print(completed_design)

# unprints = ["a", "b", "c", "d", "e"]
# prints = []
# work(unprints, prints)
# print_designs(prints)

    # def get_names(*names):
    #     for name in names:
    #         print(name)

    # get_names("a", "b", "c", "d", "e")
# def get_names(number, *names):
#     print(f"一共有{number}个")
#     for name in names:
#         print(name)

# get_names(5,"a", "b", "c", "d", "e")
# def build_profiles(name, college, **user_info):
#     user_info["name"] = name
#     user_info["college"] = college
#     print(user_info)

# build_profiles("oliver", "NTU", location="nj", like="programming")
import module
unprints = ["a", "b", "c", "d", "e"]
prints = []
module.work(unprints, prints)
module.print_designs(prints)
