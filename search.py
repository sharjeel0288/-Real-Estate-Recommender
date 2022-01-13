from fuzzywuzzy import fuzz

file1 = open('E:\\Ds-main\\project\\stringmatch.txt', 'r')
Lines = file1.readlines()

Str1 = Lines[0]
if(1 <= len(Lines)):
    Str2 = Lines[1]
else:
    file1 = open('E:\\Ds-main\\project\\result.txt', 'w')
    file1.writelines(str(100)+"\n")
    file1.writelines(str(100))
    file1.close()
    exit()
    
Ratio = fuzz.ratio(Str1.lower(), Str2.lower()) #town towm
Partial_Ratio = fuzz.partial_ratio(Str1.lower(), Str2.lower())
Token_Sort_Ratio = fuzz.token_sort_ratio(Str1, Str2)
Token_Set_Ratio = fuzz.token_set_ratio(Str1, Str2)
# print(Str1+"    "+Str2+"   "+str(Ratio)+"  "+str(Partial_Ratio)+"  "+str(Token_Sort_Ratio)+"  "+str(Token_Set_Ratio))
# print("ASfasf")
# print(Ratio)
# print(Partial_Ratio)
# print(Token_Sort_Ratio)
# print(Token_Set_Ratio)
file1 = open('E:\\Ds-main\\project\\result.txt', 'w')

file1.writelines(str(Partial_Ratio)+"\n")
file1.writelines(str(Token_Set_Ratio))
file1.close()
