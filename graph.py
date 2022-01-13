
import numpy as np
import matplotlib.pyplot as plt


file1 = open('E:\\Ds-main\\project\\graphfile.txt', 'r')
Lines = file1.readlines()
file1.close()
if(7 <= len(Lines)):
    location1 = Lines[0]
    bath1 = Lines[1]
    bedroom1 = Lines[2]
    latitude1 = Lines[3]
    longitude1 = Lines[4]
    price1 = Lines[5]
    area1 = Lines[6]
    match1 = Lines[7]
else:
    location1 = ""
    bath1 = 0
    bedroom1 = 0
    latitude1 = 0
    longitude1 = 0
    price1 = 0
    area1 = 0
    match1 = 0

if(15 <= len(Lines)):
    location2 = Lines[8]
    bath2 = Lines[9]
    bedroom2 = Lines[10]
    latitude2 = Lines[11]
    longitude2 = Lines[12]
    price2 = Lines[13]
    area2 = Lines[14]
    match2 = Lines[15]
else:
    location2 = ""
    bath2 = 0
    bedroom2 = 0
    latitude2 = 0
    longitude2 = 0
    price2 = 0
    area2 = 0
    match2 = 0
if(23 <= len(Lines)):
    location3 = Lines[16]
    bath3 = Lines[17]
    bedroom3 = Lines[18]
    latitude3 = Lines[19]
    longitude3 = Lines[20]
    price3 = Lines[21]
    area3 = Lines[22]
    match3 = Lines[23]
else:
    location3 = ""
    bath3 = 0
    bedroom3 = 0
    latitude3 = 0
    longitude3 = 0
    price3 = 0
    area3 = 0
    match3 = 0
if(31 <= len(Lines)):
    location4 = Lines[24]
    bath4 = Lines[25]
    bedroom4 = Lines[26]
    latitude4 = Lines[27]
    longitude4 = Lines[28]
    price4 = Lines[29]
    area4 = Lines[30]
    match4 = Lines[31]
else:
    location4 = ""
    bath4 = 0
    bedroom4 = 0
    latitude4 = 0
    longitude4 = 0
    price4 = 0
    area4 = 0
    match4 = 0
if(39 <= len(Lines)):
    location5 = Lines[32]
    bath5 = Lines[33]
    bedroom5 = Lines[34]
    latitude5 = Lines[35]
    longitude5 = Lines[36]
    price5 = Lines[37]
    area5 = Lines[38]
    match5 = Lines[39]
else:
    location5 = ""
    bath5 = 0
    bedroom5 = 0
    latitude5 = 0
    longitude5 = 0
    price5 = 0
    area5 = 0
    match5 = 0

fig, ax = plt.subplots(figsize =(13, 6))
# plt.figure(figsize=[15, 10])

BATH = [int(bath1), int(bath2), int(bath3), int(bath4), int(bath5)]
BEDS = [int(bedroom1), int(bedroom2), int(bedroom3), int(bedroom4), int(bedroom5)]
LATITUDE = [int(latitude1), int(latitude2), int(latitude3), int(latitude4), int(latitude5)]
LONGITUDE = [int(longitude1), int(longitude2), int(longitude3), int(longitude4), int(longitude5)]
AREA=[int(area1), int(area2), int(area3), int(area4),  int(area5)]
MATCH=[float(match1), float(match2), float(match3), float(match4), float(match5)]


X = np.arange(5)
# plt.ylim((1,88))

plt.bar(X, BEDS, color = 'black', width = 0.05)
plt.bar(X + 0.05, LATITUDE, color = 'g', width = 0.05)
plt.bar(X + 0.100,LONGITUDE , color = 'b', width = 0.05)
plt.bar(X + 0.150, MATCH, color = 'r', width = 0.05)
plt.bar(X + 0.200, BATH, color = 'purple', width = 0.05)
# plt.bar(X + 0.200, AREA, color = 'purple', width = 0.05)
# plt.bar(X + 0.0100, , color = 'orange', width = 0.025)
plt.legend(['Location', 'Price(PKR)', 'Area(SqFt)'])


# Add annotation to bars
fig.text(0.9, 0.15, 'ZAMEEN.COM', fontsize = 12,
         color ='grey', ha ='right', va ='bottom',
         alpha = 0.7)
plt.grid(color='#95a5a6', linestyle='--', linewidth=2, axis='y', alpha=0.7)
plt.title('Comparision Graph')

plt.legend([ 'BEDS', 'LATITUDE','LONGITUDE','MATCH PERCENTAGE',"BATHS"])

plt.xticks([i + 0.05 for i in range(5)], [location1+"Price : "+str(price1)+"Area : "+str(area1),location2 +"Price : "+str(price2)+"Area : "+str(area2)
                                          ,location3 +"Price : "+str(price3)+"Area : "+str(area3), location4+"Price : "+str(price4)+"Area : "+str(area4), 
                                          location5+"Price : "+str(price5)+"Area : "+str(area5)])
plt.xlabel('Properties')
plt.ylabel('Range')

# plt.savefig('4BarPlot.png')
# Displaying the bar plot
plt.show()