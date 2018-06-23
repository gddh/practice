class InstagramAccount(object):
    def __init__(self, instagram_id, username, biography, follower_count, followers):
        self.instagram_id = instagram_id
        self.username = username
        self.biography = biography
        self.follower_count = follower_count
        self.followers = followers  # List of InstagramAccount objects of all followers of this account



def is_influential(lst, acc):
    if acc.follower_count >= 3:
        lst.append(acc)
    return lst
        

"""
Top level function to crawl instagram accounts

@param seed_instagram_id: Initial instagram account ID from which to begin crawling
@return: A list of InstagramAccount objects that have a follower count greater than 5000
"""
def crawl_instagram_graph(seed_instagram_id, start):
    visited = set()
    acc = start
#    acc = api.get_account(seed_instagram_id) # unsure of API - get first endpoint
    q = [acc]
    influential_accs = []
    while (q != []):
        acc = q.pop()
        if not (acc.instagram_id in visited):
            visited.add(acc.instagram_id)
            infuential_accs = is_influential(influential_accs, acc)
            for follower in acc.followers:
                if not (follower in visited):
                    q.append(follower)
    return influential_accs

def basic_test1():
    u1 = InstagramAccount(1, 'a','b',0, [])
    u2 = InstagramAccount(2, 'a','b',1, [u1])
    u3 = InstagramAccount(3, 'a','b',2, [u1, u2])
    u4 = InstagramAccount(4, 'a','b',3, [u1, u2, u3])
    u5 = InstagramAccount(5, 'a','b',4, [u1,u2,u3,u4])
    res = crawl_instagram_graph(5, u5)
    for user in res:
        print user.instagram_id

def fully_connected_test():
    u1 = InstagramAccount(1, 'a','b',4, [])
    u2 = InstagramAccount(2, 'a','b',4, [u1])
    u3 = InstagramAccount(3, 'a','b',4, [u1, u2])
    u4 = InstagramAccount(4, 'a','b',4, [u1, u2, u3])
    u5 = InstagramAccount(5, 'a','b',4, [u1,u2,u3,u4])
    users = [u1, u2,u3,u4,u5]
    for user in users:
        tmp = [user for user in users]
        tmp.remove(user)
        user.followers = tmp
    res = crawl_instagram_graph(5, u5)
    for user in res:
        print user.instagram_id


if __name__ == "__main__":
    #basic_test1()
    fully_connected_test()
