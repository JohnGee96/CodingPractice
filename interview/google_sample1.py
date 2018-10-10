# Problem:
# Duplicate by '.', '+'
# Not by domain name after '@'
#
# FIND the number of groups more than one element
# CORRECTNESS

def solution(L):
    # First, sort the emails by the domain names
    domain_set = {} # store unique domain names
    username_set = {} # store unique usernames

    # for i in range(len(L)):
    #     _, domain = L[i].split('@')
    #     if domain in domain_set[:
    #         domain_set[domain].append(i)
    #     else:
    #         domain_set[domain] = []

    # sort by username
    for i in range(len(L)):
        username, domain_name = L[i].split('@')
        true_username = ignoreChar(username) + domain_name
        print(true_username)
        if true_username in username_set:
            username_set[true_username] += 1
        else:
            username_set[true_username] = 1
    
    result_cnt = 0
    for c in username_set.values():
        print(c)
        if c > 1:
            result_cnt += 1
    return result_cnt


def ignoreChar(s):
    s = s.replace('.', '')
    index = s.find('+')
    if index != -1:
        s = s[:index]
    return s


# print(ignoreChar("123+123"))
# print(ignoreChar("123.123"))
# print(ignoreChar("123+123.123"))
# print(ignoreChar("123.123+123"))

print(solution(['a.b@example.com', 'x@example.com', 'x@exa.mple.com', 'ab+1@example.com', 'y@example.com', 'y@example.com', 'y@example.com']))

