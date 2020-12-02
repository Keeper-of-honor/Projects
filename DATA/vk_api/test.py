import vk_api
#from toks import main_token
session = vk_api.VkApi(token='d7cebb6d0f4e30c28bd85c3a03d2283b525c3616e44e5dae730b79b4008779b13450ad93e83f6983a6d9b')
print(session.method('users.get', {'user_ids': 210700286, 'fields': 'photo_50, city, verified'}))
