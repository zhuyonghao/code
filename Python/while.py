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

def great_user(username, gender):
    print(f"Hello! {username}是{gender}!")

great_user(gender = "男生", username = "小明")

