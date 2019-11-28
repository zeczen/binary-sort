def lion_sort(lst):
    for key in range(1, len(lst)):
        organ = lst.pop(key)
        location = lion_speak1(lst[:key], organ, key // 2)
        lst.insert(location, organ)

    return lst
    
    
def lion_speak(lst, search, count):
    length = len(lst)
    # search for the location of 'search'
    while length >= 2:
        index = length // 2
        mid = lst[index]
        if mid < search:
            lst = lst[index + 1:]
            count += ((length + 3) // 4)
            length = len(lst)
            continue
        elif mid > search:
            lst = lst[:index]
            count -= ((length + 2) // 4)
            length = len(lst)
            continue
        elif mid == search:
            return count
    if length == 1:
        if lst[0] < search:
            return count + 1
    return count
