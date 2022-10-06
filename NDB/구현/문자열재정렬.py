array = list(input())
character = []
added = 0
for i in range(len(array)):
    if array[i].isdigit():
        added += int(array[i])
    else:
        character.append(array[i])
        
character.sort()
for i in character:
    print(i, end='')
print(added)