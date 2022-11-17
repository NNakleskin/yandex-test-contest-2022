def space_del(str):
    str = str.split()
    str = ' '.join(str)
    return str

def remove_special_symbols(str):
    spec_sym = ['!', '?', '"', ';', "'", ",", ".", '-', '']
    for symbol in str:
        str = str.replace(symbol, "")
        return str

def cut_spec_sum(str):
    str = space_del(str)
    str = remove_special_symbols(str)
    return str


f = open("encoded.txt", "r")
text = f.read()
f.close()


col = 0
alphabet = ['а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 
            'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 
            'ч', 'ш', 'щ', 'ъ', "", 'э', 'ю', 'я']

text = cut_spec_sum(text).lower()
l = len(text)

list_p = []

for char in alphabet:
    for symbol in text:
        if char == symbol:
            col += 1
    proz = col * 100 / l
    print(char, round(proz, 2))
    list_p.append(round(proz, 2))
    col = 0
    proz = 0

list_p.sort()
print(list_p)