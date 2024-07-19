def work(unprint_designs, completed_designs):
    while unprint_designs:
        design = unprint_designs.pop()
        print(design)
        completed_designs.append(design)

def print_designs(completed_designs):
    for completed_design in completed_designs:
        print(completed_design)
