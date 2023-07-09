# convert string into a list of int pairs from 0-25
def string_to_digraphs(input_string):
    digraphs = []
    for i in range(0, len(input_string), 2):
        char1 = ord(input_string[i])
        char2 = ord(input_string[i+1]) if i+1 < len(input_string) else ord('x') 
        digraphs.append([char1 - 97, char2 - 97])
    return digraphs

# map digraph to int
def digraph_to_int(digraph):
    return digraph[0] * 100 + digraph[1] # M = a * 100 + b

# encode integer M with C = M^e mod n
def encode(M, e, n):
    return pow(M, e, n)

# decode integer with M = C^d mod n
def decode(C, d, n):
    return pow(C, d, n)       

def int_to_digraph(M):
    return [M // 100, M % 100]

# converts ascii value into character. 97 added to cancel left shift
def int_to_string(n):
    return (chr(n+97))

# Returns a string from a list of digraphs
def diagraph_to_string(digraph):
    s = ""

    for a,b in digraph:
            s += int_to_string(a) + int_to_string(b)

    if s[-1] == 'x':
            s = s[:-1] # remove x

    return(s)

def encode_msg(msg, e, n):
    # convert string into a list of digraphs
    msg_digrahps = string_to_digraphs(msg)

    # convert a list containing a digraph into an integer
    msg_mapped_ints = []
    for digraph in msg_digrahps:
        msg_mapped_ints.append(digraph_to_int(digraph))

    # encode integers
    encoded_ints = []
    for integer in msg_mapped_ints:
        encoded_ints.append(encode(integer, e, n))

    return encoded_ints

def decode_msg(encoded_ints, d, n):
    # decode integers to get original integers M
    decoded_ints = []
    for C in encoded_ints:
        decoded_ints.append(decode(C, d, n))

    # get msg digraph again
    msg_digrahps = []
    for M in decoded_ints:
        msg_digrahps.append(int_to_digraph(M))

    # return message 
    return diagraph_to_string(msg_digrahps)

def main():
    p = 1907
    q = 2411
    n = p * q
    d = 1299277
    e = 63273
    msg_list = ["whatdoyoumeanbythat", "itiswhatitis", "bruh", "okmanigetit", "decodethismessage"]
    denny_encoded = [2199694, 1482975, 2042587, 2598228, 402377, 233599, 3883944, 1902849, 3081398, 3416270, 2292067, 4198527, 233599, 3127180, 2117085, 2872024, 3665779, 1308002, 3416270, 99586, 1967101, 4063678, 3317983, 3930606, 3375403, 3252047, 1342815, 1610338, 956191, 228847, 290788, 1328972, 1342815, 2759204, 1480689, 1864511, 2326966, 1954719, 1800141, 4499720, 1308002, 1004489, 1342815, 1610338, 1342815, 1510048, 2562488, 2326966, 1954719, 1419121, 2115231, 233599, 1820189, 1793982, 2759204, 3925179, 3386564, 1849093, 24516, 1954719, 4090342, 24516, 1820189, 2312278, 233599, 1004489, 3237874, 2813336, 1610338, 402377, 4085220, 2326966, 1954719, 2930941, 4124719, 233599, 2461255, 3665779, 2076888, 3855074, 24516]

    # print my test cases
    for msg in msg_list:
        encoded_ints = encode_msg(msg, e, n)
        print(encoded_ints)
        decoded_msg = decode_msg(encoded_ints, d, n)
        print(decoded_msg)

    # print dr denny's secret message
    denny_msg = decode_msg(denny_encoded, d, n)
    print(denny_encoded)
    print(denny_msg)

main() 
