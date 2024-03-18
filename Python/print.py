print("hello", "world", "12345" , sep = "a", end = "0")
f = open("hello.txt", 'w')
print("hello world", file = f)
f.close()