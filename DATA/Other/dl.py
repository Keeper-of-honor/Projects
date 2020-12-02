import requests as req
import xml.etree.ElementTree as ET
import base64
from PIL import Image
import xmltodict
from io import BytesIO
# from fpdf import FPDF
from PyPDF2 import PdfFileWriter, PdfFileReader
import os
import json
import argparse

try:
    script_path = os.path.dirname(os.path.realpath(__file__))
    os.mkdir(script_path+'/books/')
except:
    pass

# </slice6></bookpages></stdresponse>
# cookies = {
#     'Host': 'znanium.com',
#     'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:76.0) Gecko/20100101 Firefox/76.0',
#     'Accept': 'application/xml, text/xml, */*; q=0.01',
#     'Accept-Language': 'ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3',
#     'Accept-Encoding': 'gzip, deflate, br',
#     'X-CSRF-Token': '_FMcUrY8-eGjn6XeDFUh7x3Ncb5Wlt1qLa1Bi5SpGFLPDHco4ledg5X97ZphMlWCV_49zTjM6Edf1wDk3JltFg==',
#     'X-Requested-With': 'XMLHttpRequest',
#     'Connection': 'keep-alive',
#     'Referer': 'https://znanium.com/read?id=333180',
#     'Cookie': '_csrf-frontend=d10b4b2e5eecf610fa898f2821dc67b5f48ad4695ce63d690cb07b054918a6d5a%3A2%3A%7Bi%3A0%3Bs%3A14%3A%22_csrf-frontend%22%3Bi%3A1%3Bs%3A32%3A%223_kzTkdb6bHDmgtmJ3LsnZ5-rzAoH0uD%22%3B%7D; znanium=en455cus5ig2h8v1r6ubd49hui; _identity_zn=1fd1382cb864356ed964688b84d6fef6e0228c837fad05c300f9263e9e9c7f19a%3A2%3A%7Bi%3A0%3Bs%3A12%3A%22_identity_zn%22%3Bi%3A1%3Bs%3A51%3A%22%5B441200%2C%22d5Bc7C5ot28_hKzCN_5irBp-Y2XIA1tV%22%2C2592000%5D%22%3B%7D'
# }
# from fpdf import FPDF
# pdf = FPDF()
# # imagelist is the list with all image filenames
# for image in imagelist:
#     pdf.add_page()
#     pdf.image(image,x,y,w,h)
# pdf.output("yourfile.pdf", "F")
# session = req.Session()
# session.cookies['_identity_zn'] = '1fd1382cb864356ed964688b84d6fef6e0228c837fad05c300f9263e9e9c7f19a%3A2%3A%7Bi%3A0%3Bs%3A12%3A%22_identity_zn%22%3Bi%3A1%3Bs%3A51%3A%22%5B441200%2C%22d5Bc7C5ot28_hKzCN_5irBp-Y2XIA1tV%22%2C2592000%5D%22%3B%7D'



def get_page(book, page, session: req.Session):
    res = session.get('https://znanium.com/read/page/?doc={0}&pgnum={1}&currnum={1}&s=undefined'.format(book, page))
    print(page, res, end='')
    root: xmltodict.OrderedDict = xmltodict.parse(res.text)
    print(' '+root['stdresponse']['status'], root['stdresponse']['status_text'])

    if str(root['stdresponse']['status']) != '0':
        print(res.text)
        return None

    page_img = Image.new('RGB', (0,0))
    for i,slice_b64 in enumerate(root['stdresponse']['bookpages'].values()):
        if i == 0:
            page_img = Image.open(BytesIO(base64.b64decode(slice_b64.split(',')[1])))
            continue
        slice_img = Image.open(BytesIO(base64.b64decode(slice_b64.split(',')[1])))
        new_img = Image.new('RGB', (page_img.width, page_img.height + slice_img.height))
        new_img.paste(page_img, (0, 0))
        new_img.paste(slice_img, (0, page_img.height))
        page_img = new_img
        #new_img.save('img{}.png'.format(i))
    return page_img

def auth(login, password):
    # BROKEN
    session = req.Session()
    session.get('https://get')
    headers = {	
    'Host': 'znanium.com',
    'Origin': 'https://znanium.com',
    'Referer': 'https://znanium.com/site/login',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:76.0) Gecko/20100101 Firefox/76.0',
    }
    data = {"LoginForm[username]": login,"LoginForm[password]":password,"LoginForm[productId]":"","LoginForm[cartSection]":"","LoginForm[rememberMe]":"1","login-button":""}
    res = session.post('https://znanium.com/site/login', data=data, headers=headers)
    print(res)
    print(res.cookies)
    #print(res.text)
    return session

def download_book(book, session, pages=None):
    try:
        os.mkdir(script_path+'/pages/{0}'.format(book))
    except:
        pass
    pdf = PdfFileWriter()
    #for page in range(pages[0], pages[1]+1):
    page = 1 if pages==None else pages[0]
    while True:
        if (pages[1] >= 1) and (page >= pages[1]):
            break

        page_img = get_page(book, page, session)
        if page_img == None:
            break
        page_img.save(script_path+'/pages/{0}/{1}.pdf'.format(book, page))

        page_pdf = BytesIO()
        page_img.save(page_pdf, format='PDF')
        
        page_pdf_obj = PdfFileReader(page_pdf)
        pdf.addPage(page_pdf_obj.getPage(0))

        page += 1

    pdf.write(open(script_path+'/books/{}.pdf'.format(book), 'wb'))

config = json.load(open(script_path+'/config.json'))
#session = auth(config['login'], config['password'])
session = req.Session()
session.cookies['_identity_zn'] = config['cookie']

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Download books from Znanium.com')
    parser.add_argument('book_id', metavar='book_id', type=int, nargs=1,
                    help='ID of book')
    parser.add_argument('-s', metavar='start', type=int, nargs=1, default=1,
                    help='download from this page')
    parser.add_argument('-e', metavar='end', type=int, nargs=1, default=-1,
                    help='download to this page')

    args = parser.parse_args()

    download_book(args.book_id, session, pages=(args.s, args.e))

