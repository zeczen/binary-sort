
def binary_sort(lst):
    for key in range(1, len(lst)):
        element = lst.pop(key)
        location = _binaryInsert(lst[:key], element)
        lst.insert(location, element)

    return lst


def _binaryInsert(lst, search):
    length = len(lst)
    right = length - 1
    left = 0
    mid = length // 2
    while right > left:

        if lst[mid] > search:
            right = mid - 1
            mid = (right + left) // 2

        elif lst[mid] < search:
            left = mid + 1
            mid = (right + left) // 2

        elif lst[mid] == search:
            return mid

    if (right <= left):
        if mid < 0: return 0
        if lst[mid] < search:
            return mid + 1
        if left == right and lst[mid - 1] < search < lst[mid]:
            return mid

    return mid
