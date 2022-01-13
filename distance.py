from geopy.geocoders import Nominatim
from geopy import distance


file1 = open('E:\\Ds-main\\project\\graphfile.txt', 'r')
Lines = file1.readlines()
file1.close()
if(7 <= len(Lines)):
    location1 = Lines[0]
else:
    location1 = ""


if(15 <= len(Lines)):
    location2 = Lines[8]
else:
    location2 = ""

if(23 <= len(Lines)):
    location3 = Lines[16]
else:
    location3 = ""

if(31 <= len(Lines)):
    location4 = Lines[24]
else:
    location4 = ""

if(39 <= len(Lines)):
    location5 = Lines[32]
else:
    location5 = ""


source = input("Enter your source location : ")

geocoder = Nominatim(user_agent="i know")


print("Flight distance from "+source+" to ")

loc1 = source
if(location1 != ""):
    loc2 = location1
    coordinates1 = geocoder.geocode(loc1)
    coordinates2 = geocoder.geocode(loc2)
    lat1, long1 = (coordinates1.latitude, coordinates1.longitude)
    lat2, long2 = (coordinates1.latitude, coordinates2.longitude)
    place1 = (lat1, long1)
    place2 = (lat2, long2)
    print(str(distance.distance(place1, place2)) + "  " + location1)

if(location2 != "" and location2 != location1):
    loc2 = location2
    coordinates1 = geocoder.geocode(loc1)
    coordinates2 = geocoder.geocode(loc2)
    lat1, long1 = (coordinates1.latitude, coordinates1.longitude)
    lat2, long2 = (coordinates1.latitude, coordinates2.longitude)
    place1 = (lat1, long1)
    place2 = (lat2, long2)
    print(str(distance.distance(place1, place2)) + "  " + location2)

if(location3 != "" and location3 != location1 and location3 != location2):
    loc2 = location3
    coordinates1 = geocoder.geocode(loc1)
    coordinates2 = geocoder.geocode(loc2)
    lat1, long1 = (coordinates1.latitude, coordinates1.longitude)
    lat2, long2 = (coordinates1.latitude, coordinates2.longitude)
    place1 = (lat1, long1)
    place2 = (lat2, long2)
    print(str(distance.distance(place1, place2)) + "  " + location3)

if(location4 != "" and location4 != location1 and location4 != location2 and location4 != location3):
    loc2 = location4
    coordinates1 = geocoder.geocode(loc1)
    coordinates2 = geocoder.geocode(loc2)
    lat1, long1 = (coordinates1.latitude, coordinates1.longitude)
    lat2, long2 = (coordinates1.latitude, coordinates2.longitude)
    place1 = (lat1, long1)
    place2 = (lat2, long2)
    print(str(distance.distance(place1, place2)) + "  " + location4)

if(location5 != "" and location5 != location1 and location5 != location2 and location5 != location3 and location5 != location4):
    loc2 = location5
    coordinates1 = geocoder.geocode(loc1)
    coordinates2 = geocoder.geocode(loc2)
    lat1, long1 = (coordinates1.latitude, coordinates1.longitude)
    lat2, long2 = (coordinates1.latitude, coordinates2.longitude)
    place1 = (lat1, long1)
    place2 = (lat2, long2)
    print(str(distance.distance(place1, place2)) + "  " + location5)
