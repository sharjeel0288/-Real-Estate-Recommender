#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <algorithm>
using namespace std;
float matchsub(int_fast64_t a, int_fast64_t b);
float tenPercent(int_fast64_t n);
class Node
{
public:
    int baths, area_marla, area_sqft, bedrooms;
    int_fast64_t price, latitude, longitude, property_id, location_id;
    string page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent;
    Node *left;
    Node *right;
    Node *mid;
    Node(int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
         int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
         string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
         string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-")
    {

        this->baths = baths;
        this->area_marla = area_marla;
        this->area_sqft = area_sqft;
        this->bedrooms = bedrooms;
        this->bedrooms = bedrooms;
        this->price = price;
        this->latitude = latitude;
        this->longitude = longitude;
        this->property_id = property_id;
        this->location_id = location_id;
        this->page_url = page_url;
        this->property_type = property_type;
        this->price_bin = price_bin;
        this->location = location;
        this->city = city;
        this->province_name = province_name;
        this->locality = locality;
        this->area = area;
        this->purpose = purpose;
        this->agency = agency;
        this->agent = agent;
        this->left = NULL;
        this->right = NULL;
        this->mid = NULL;
    }
};
class LinklistNode
{
public:
    int baths, area_marla, area_sqft, bedrooms;
    float match;
    int_fast64_t price, latitude, longitude, property_id, location_id;
    string page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent;
    LinklistNode *next;
    LinklistNode(int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
                 int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
                 string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
                 string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-", float match = 0)
    {
        next = NULL;
        this->baths = baths;
        this->area_marla = area_marla;
        this->area_sqft = area_sqft;
        this->bedrooms = bedrooms;
        this->bedrooms = bedrooms;
        this->price = price;
        this->latitude = latitude;
        this->longitude = longitude;
        this->property_id = property_id;
        this->location_id = location_id;
        this->page_url = page_url;
        this->property_type = property_type;
        this->price_bin = price_bin;
        this->location = location;
        this->city = city;
        this->province_name = province_name;
        this->locality = locality;
        this->area = area;
        this->purpose = purpose;
        this->agency = agency;
        this->agent = agent;
        this->match = match;
    }
};
class Pqueue
{
    LinklistNode *head;

public:
    Pqueue()
    {
        head = NULL;
    }
    bool search(int property_id)
    {
        LinklistNode *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->property_id == property_id)
                return true;
            ptr = ptr->next;
        }
        return false;
    }
    void Graph()
    {
        LinklistNode *temp = head;
        string myText;
        ofstream MyFile("graphfile.txt");
        while (temp != NULL)
        {
            MyFile << temp->location << endl
                   << temp->baths << endl
                   << temp->bedrooms << endl
                   << temp->latitude << endl
                   << temp->longitude << endl
                   << temp->price << endl
                   << temp->area_sqft << endl
                   << temp->match << endl;
            temp = temp->next;
        }
        MyFile.close();
        system("Python graph.py ok go");
    }
    void enqueue(int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
                 int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
                 string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
                 string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-", float match = 0)
    {

        register LinklistNode *ptr = new LinklistNode(baths, area_marla, area_sqft, bedrooms,
                                                      price, latitude, longitude, property_id, location_id,
                                                      page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent, match);

        if (search(property_id))
            return;

        if (head == NULL)
        {
            head = ptr;
            return;
        }
        register bool isadded = false;
        register LinklistNode *temp = head->next;
        register LinklistNode *temp2 = head;
        if (match > head->match)
        {
            ptr->next = head;
            head = ptr;
            return;
        }
        while (temp != NULL) //  20  10        15
        {
            if (match > temp->match)
            {
                temp2->next = ptr;
                ptr->next = temp;
                isadded = true;
                break;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        if (!isadded)
        {
            temp2->next = ptr;
        }
    }
    void MoreDetails(int id)
    {
        LinklistNode *temp = head;
        bool found = false;
        while (temp != NULL)
        {
            if (temp->property_id == id)
            {
                cout << "PAGE : " << temp->page_url << endl
                     << "AGENT : " << temp->agent << endl
                     << "AGENCY : " << temp->agency << endl
                     << "LOCALITY : " << temp->locality << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Enter valid property-ID" << endl;
    }
    inline int NoOfNode()
    {
        register LinklistNode *ptr = head;
        register int i = 0;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        return i;
    }
    int dequeue()
    {
        if (head == NULL)
        {
            return -999;
        }
        LinklistNode *temp = head;
        // int key = temp->data;
        head = head->next;
        delete temp;
        // return key;
    }
    void triversal()
    {
        LinklistNode *ptr = head;
        int i = 0;
        while (ptr != NULL && i < 10)
        {
            // if (ptr->match >= 80)
            cout << "PROPERTY ID : " << ptr->property_id << "\t\t PROPERTY TYPE : " << ptr->property_type << "\t\t PRICE : " << ptr->price
                 << "\t\tPRICE PREDICT : " << ptr->price_bin << "\t\t LOCATION : " << ptr->location << endl
                 << "CITY : " << ptr->city << "\t\t ADDRESS : " << ptr->locality
                 << "LATITUDE : " << ptr->latitude << "\t\t LONGITUDE : " << ptr->longitude << "\t\t BATHS : " << ptr->baths << "\t\t BEDS : " << ptr->bedrooms << endl
                 << "\t\tAREA : " << ptr->area << "\t\t AREA MARLA : " << ptr->area_marla << "\t\t AREA SQRFT : " << ptr->area_sqft << "\t\t PURPOSE : " << ptr->purpose;
            //   cout   << ptr->agency << "\t" <<endl;
            // cout<< ptr->agent << endl;
            cout << "\t\t MATCH PERCENTAGE : " << ptr->match << endl
                 << endl;
            ptr = ptr->next;
            i++;
        }
        cout << endl;
    }
    int length()
    {
        int i = 0;
        LinklistNode *ptr = head;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        return i;
    }
};
class BST
{
    Node *root;
    void preOrderTri(Node *r)
    {
        if (r != NULL)
        {
            {
                // cout << r->data << "\t";
                preOrderTri(r->left);
                //				cout<<"\t/";
                preOrderTri(r->right);
                //				cout<<"\t\t";
            }
        }
    }
    void inOrderTri(Node *r)
    {
        if (r != NULL)
        {

            inOrderTri(r->left);
            //				cout<<"\t";
            // cout << r->data << "\t";
            inOrderTri(r->right);
            //				cout<<"\t\t";
        }
    }
    void postOrderTri(Node *r)
    {
        if (r != NULL)
        {

            postOrderTri(r->left);
            //			cout<<"\t";
            postOrderTri(r->mid);

            postOrderTri(r->right);
            cout << r->agent << endl;
            // cout << r->property_id
            //      << "\t\t" << r->location_id
            //      << "\t\t" << r->property_type
            //      << "\t\t" << r->price
            //      << "\t\t" << r->price_bin
            //      << "\t\t" << r->location
            //      << "\t\t" << r->province_name
            //      << "\t\t" << r->locality
            //      << "\t\t" << r->city << endl;
        }
    }
    Node *recursiveSearch(Node *r, int val)
    {
        if (r == NULL)
        {
            cout << "Not found" << endl;
            return NULL;
        }
        if (r->price == val)
            return r;

        else if (val < r->price)
            return recursiveSearch(r->left, val);

        else
            return recursiveSearch(r->right, val);
    }
    // bool ifBST(Node *r, Node *left, Node *right)
    // {

    //     if (root == NULL)
    //         return true;
    //     if (left != NULL and root->price <= left->price)
    //         return false;

    //     if (right != NULL && root->price >= right->price)
    //         return false;

    //     if (ifBST(root->left, left, root))
    //         return true;
    //     if (ifBST(root->right, root, right))
    //         return true;
    // }

    Node *inordersucessor(Node *r)
    {
        Node *c = r;
        while (c && c->left != NULL)
        {
            c = c->left;
        }
        return c;
    }
    // Node *delInBST(Node *r, int v)
    // {
    //     // base case
    //     Node *temp;
    //     if (r == NULL)
    //     {
    //         return NULL;
    //     }
    //     else if (v < r->data)
    //     {
    //         r->left = delInBST(r->left, v);
    //     }

    //     else if (v > r->data)
    //     {
    //         r->right = delInBST(r->right, v);
    //     }

    //     else
    //     {
    //         if (r->left == NULL && r->right == NULL)
    //         {
    //             delete (r); // wipe out the memory, in C, use free function
    //             r = NULL;
    //         }

    //         else if (r->left == NULL)
    //         {
    //             temp = r->right;
    //             delete r;
    //             return temp;
    //         }
    //         else if (r->right == NULL)
    //         {
    //             temp = r->left;
    //             delete r;
    //             return temp;
    //         }
    //         else
    //         {

    //             temp = inordersucessor(r->right);

    //             r->data = temp->data;

    //             r->right = delInBST(r->right, temp->data);
    //         }
    //     }
    //     return r;
    // }
    int height(Node *r)
    {
        if (r == NULL)
            return 0;
        else
        {
            int left_height = height(r->left);
            int right_height = height(r->right);
            if (left_height >= right_height)
                return left_height + 1;
            else
                return right_height + 1;
        }
    }
    float fuzzysearch(string a, string b)
    {

        string myText;
        ofstream MyFile("stringmatch.txt");
        MyFile << a << endl
               << b;
        MyFile.close();
        system("Python search.py ok go");
        // cout << "ret/cpp = " << ret << endl;
        ifstream MyReadFile("result.txt");
        getline(MyReadFile, myText);

        float resultpercent1 = stof(myText);
        getline(MyReadFile, myText);

        float resultpercent2 = stof(myText);
        MyReadFile.close();
        // cout << "\t\t\t\\t\t\\t\t\t" << resultpercent1 << "\t\t\t\t" << resultpercent2 << endl;
        if (resultpercent2 > resultpercent1)
            return resultpercent2;
        return resultpercent1;
    }
    void calcITOPrice(float divid, Node *r, Pqueue &queue, int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
                      int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
                      string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
                      string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-", float match = 0)
    {
        divid += 1;
        cout << ".";
        match = 1;
        if (r != NULL)
        {
            if (price == 0 || (r->price >= price - tenPercent(price) && r->price <= price + tenPercent(price)))
            {
                if (price == 0)
                    match += 0;
                else
                {
                    match += matchsub(r->price, price);
                }
            }
            // cout << "price : " << match << "\t";

            if (area_sqft == 0 || r->area_sqft >= area_sqft - tenPercent(area_sqft) && r->area_sqft <= area_sqft + tenPercent(area_sqft))
            {
                if (area_sqft == 0)
                    match += 0;
                else
                {
                    match += matchsub(r->area_sqft, area_sqft);
                }
            }
            // cout << "area sqft : " << match << "\t";

            if (bedrooms == 0 || r->bedrooms >= bedrooms - tenPercent(bedrooms) && r->bedrooms <= bedrooms + tenPercent(bedrooms))
            {
                if (bedrooms == 0)
                    match += 0;
                else
                {
                    match += matchsub(r->bedrooms, bedrooms);
                }
            }
            // cout << "bedrooms : " << match << "\t";

            if (property_type == "-")
                match += 0;
            else
            {
                match += fuzzysearch(r->property_type, property_type);
            }
            // cout << "property type : " << match << "\t";

            if (price_bin == "-")
                match += 0;
            else
            {
                match += fuzzysearch(r->price_bin, price_bin);
            }
            // cout << match << "\t";
            if (location == "-")
                match += 0;
            else
            {
                match += (fuzzysearch(r->location, location));
            }
            // cout << "location : " << match << "\t";
            // usleep(3000000);
            if (divid == 0)
            {
                divid = 1;
                match = 1;
            }
            // cout << "\tmatch : " << match << "\tDiviser : " << divid << endl;
            match /= divid;
            match *= 100;
            // cout << "final : " << match << endl;
            // cout << ".";
            if (queue.NoOfNode() <= 5)
            {
                if (match >= 70)
                    queue.enqueue(r->baths, r->area_marla, r->area_sqft, r->bedrooms, r->price,
                                  r->latitude, r->longitude, r->property_id, r->location_id,
                                  r->page_url, r->property_type, r->price_bin, r->location, r->city,
                                  r->province_name, r->locality, r->area, r->purpose, r->agency, r->agent, match);
                match = 0;
                if ((r->price >= price - tenPercent(price)) && (r->price <= price + tenPercent(price)))
                {
                    // this->calcITOPrice(r->left, queue, baths, area_marla, area_sqft, bedrooms, price,
                    //                    latitude, longitude, property_id, location_id,
                    //                    page_url, property_type, price_bin, location, city,
                    //                    province_name, locality, area, purpose, agency, agent, 0);
                    this->calcITOPrice(divid, r->mid, queue, baths, area_marla, area_sqft, bedrooms, price,
                                       latitude, longitude, property_id, location_id,
                                       page_url, property_type, price_bin, location, city,
                                       province_name, locality, area, purpose, agency, agent, 0);
                    // this->calcITOPrice(r->right, queue, baths, area_marla, area_sqft, bedrooms, price,
                    //                    latitude, longitude, property_id, location_id,
                    //                    page_url, property_type, price_bin, location, city,
                    //                    province_name, locality, area, purpose, agency, agent, 0);
                }
                if ((r->price > price - tenPercent(price)))
                {
                    this->calcITOPrice(divid, r->left, queue, baths, area_marla, area_sqft, bedrooms, price,
                                       latitude, longitude, property_id, location_id,
                                       page_url, property_type, price_bin, location, city,
                                       province_name, locality, area, purpose, agency, agent, 0);
                }
                if (r->price <= price + tenPercent(price))
                {
                    this->calcITOPrice(divid, r->right, queue, baths, area_marla, area_sqft, bedrooms, price,
                                       latitude, longitude, property_id, location_id,
                                       page_url, property_type, price_bin, location, city,
                                       province_name, locality, area, purpose, agency, agent, 0);
                }
            }
        }
    }
    void calcITOBedrooms(float divid, Node *r, Pqueue &queue, int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
                         int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
                         string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
                         string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-", float match = 0)
    {
        divid += 1;
        cout << ".";
        match = 1;
        if (r != NULL)
        {
            if (price == 0 || (r->price >= price - tenPercent(price) && r->price <= price + tenPercent(price)))
            {
                if (price == 0)
                    match += 0;
                else
                {
                    match += matchsub(r->price, price);
                }
            }
            // cout << match << "\t";

            if (area_sqft == 0 || r->area_sqft >= area_sqft - tenPercent(area_sqft) && r->area_sqft <= area_sqft + tenPercent(area_sqft))
            {
                if (area_sqft == 0)
                    match += 0;
                else
                {
                    match += matchsub(r->area_sqft, area_sqft);
                }
            }
            // cout << match << "\t";

            if (bedrooms == 0 || r->bedrooms >= bedrooms - tenPercent(bedrooms) && r->bedrooms <= bedrooms + tenPercent(bedrooms))
            {
                if (bedrooms == 0)
                    match += 0;
                else
                {
                    match += matchsub(r->bedrooms, bedrooms);
                }
            }
            // cout << match << "\t";

            if (property_type == "-")
                match += 0;
            else
            {
                match += fuzzysearch(r->property_type, property_type);
            }
            // cout << match << "\t";

            if (location == "-")
                match += 0;
            else
            {
                match += (fuzzysearch(r->location, location));
            }
            // cout << match << "\t";

            if (price_bin == "-")
                match += 0;
            else
            {
                match += fuzzysearch(r->price_bin, price_bin);
            }
            // cout << match << "\t";
            // usleep(3000000);
            if (divid == 0)
            {
                divid = 1;
                match = 1;
            }
            match /= divid;
            match *= 100;
            // cout << match << endl;
            // cout << ".";
            if (queue.NoOfNode() <= 5)
            {
                if (match >= 70)
                    queue.enqueue(r->baths, r->area_marla, r->area_sqft, r->bedrooms, r->price,
                                  r->latitude, r->longitude, r->property_id, r->location_id,
                                  r->page_url, r->property_type, r->price_bin, r->location, r->city,
                                  r->province_name, r->locality, r->area, r->purpose, r->agency, r->agent, match);
                match = 0;
                if ((r->bedrooms >= bedrooms - tenPercent(bedrooms)) && (r->bedrooms <= bedrooms + tenPercent(bedrooms)))
                {
                    this->calcITOBedrooms(divid, r->left, queue, baths, area_marla, area_sqft, bedrooms, price,
                                          latitude, longitude, property_id, location_id,
                                          page_url, property_type, price_bin, location, city,
                                          province_name, locality, area, purpose, agency, agent, 0);
                    this->calcITOBedrooms(divid, r->mid, queue, baths, area_marla, area_sqft, bedrooms, price,
                                          latitude, longitude, property_id, location_id,
                                          page_url, property_type, price_bin, location, city,
                                          province_name, locality, area, purpose, agency, agent, 0);
                    this->calcITOBedrooms(divid, r->right, queue, baths, area_marla, area_sqft, bedrooms, price,
                                          latitude, longitude, property_id, location_id,
                                          page_url, property_type, price_bin, location, city,
                                          province_name, locality, area, purpose, agency, agent, 0);
                }
                if ((r->bedrooms > bedrooms - tenPercent(bedrooms)))
                {
                    this->calcITOBedrooms(divid, r->left, queue, baths, area_marla, area_sqft, bedrooms, price,
                                          latitude, longitude, property_id, location_id,
                                          page_url, property_type, price_bin, location, city,
                                          province_name, locality, area, purpose, agency, agent, 0);
                }
                if (r->bedrooms <= bedrooms + tenPercent(bedrooms))
                {
                    this->calcITOBedrooms(divid, r->right, queue, baths, area_marla, area_sqft, bedrooms, price,
                                          latitude, longitude, property_id, location_id,
                                          page_url, property_type, price_bin, location, city,
                                          province_name, locality, area, purpose, agency, agent, 0);
                }
            }
        }
    }
    void calcITOSqrFt(float divid, Node *r, Pqueue &queue, int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
                      int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
                      string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
                      string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-", float match = 0)
    {
        cout << ".";
        divid += 1;
        match = 1;
        if (r != NULL)
        {
            if (price == 0 || (r->price >= price - tenPercent(price) && r->price <= price + tenPercent(price)))
            {
                if (price == 0)
                    match += 0;
                else
                {
                    match += matchsub(r->price, price);
                }
            }
            // cout << match << "\t";

            if (area_sqft == 0 || r->area_sqft >= area_sqft - tenPercent(area_sqft) && r->area_sqft <= area_sqft + tenPercent(area_sqft))
            {
                if (area_sqft == 0)
                    match += 0;
                else
                {
                    match += matchsub(r->area_sqft, area_sqft);
                }
            }
            // cout << match << "\t";

            if (bedrooms == 0 || r->bedrooms >= bedrooms - tenPercent(bedrooms) && r->bedrooms <= bedrooms + tenPercent(bedrooms))
            {
                if (bedrooms == 0)
                    match += 0;
                else
                {
                    match += matchsub(r->bedrooms, bedrooms);
                }
            }
            // cout << match << "\t";

            if (property_type == "-")
                match += 0;
            else
            {
                match += fuzzysearch(r->property_type, property_type);
            }
            // cout << match << "\t";

            if (location == "-")
                match += 0;
            else
            {
                match += (fuzzysearch(r->location, location));
            }
            // cout << match << "\t";

            if (price_bin == "-")
                match += 0;
            else
            {
                match += fuzzysearch(r->price_bin, price_bin);
            }
            // cout << match << "\t";
            // usleep(3000000);
            if (divid == 0)
            {
                divid = 1;
                match = 1;
            }
            match /= divid;
            match *= 100;
            // cout << match << endl;
            // cout << ".";'
            if (queue.NoOfNode() <= 5)
            {
                if (match >= 70)
                    queue.enqueue(r->baths, r->area_marla, r->area_sqft, r->bedrooms, r->price,
                                  r->latitude, r->longitude, r->property_id, r->location_id,
                                  r->page_url, r->property_type, r->price_bin, r->location, r->city,
                                  r->province_name, r->locality, r->area, r->purpose, r->agency, r->agent, match);
                match = 0;
                if ((r->area_sqft >= area_sqft - tenPercent(area_sqft)) && (r->area_sqft <= area_sqft + tenPercent(area_sqft)))
                {
                    this->calcITOBedrooms(divid, r->left, queue, baths, area_marla, area_sqft, bedrooms, price,
                                          latitude, longitude, property_id, location_id,
                                          page_url, property_type, price_bin, location, city,
                                          province_name, locality, area, purpose, agency, agent, 0);
                    this->calcITOSqrFt(divid, r->mid, queue, baths, area_marla, area_sqft, bedrooms, price,
                                       latitude, longitude, property_id, location_id,
                                       page_url, property_type, price_bin, location, city,
                                       province_name, locality, area, purpose, agency, agent, 0);
                    this->calcITOBedrooms(divid, r->right, queue, baths, area_marla, area_sqft, bedrooms, price,
                                          latitude, longitude, property_id, location_id,
                                          page_url, property_type, price_bin, location, city,
                                          province_name, locality, area, purpose, agency, agent, 0);
                }
                if ((r->area_sqft > area_sqft - tenPercent(area_sqft)))
                {
                    this->calcITOSqrFt(divid, r->left, queue, baths, area_marla, area_sqft, bedrooms, price,
                                       latitude, longitude, property_id, location_id,
                                       page_url, property_type, price_bin, location, city,
                                       province_name, locality, area, purpose, agency, agent, 0);
                }
                if (r->area_sqft <= area_sqft + tenPercent(area_sqft))
                {
                    this->calcITOSqrFt(divid, r->right, queue, baths, area_marla, area_sqft, bedrooms, price,
                                       latitude, longitude, property_id, location_id,
                                       page_url, property_type, price_bin, location, city,
                                       province_name, locality, area, purpose, agency, agent, 0);
                }
            }
        }
    }

public:
    BST()
    {
        root = 0;
    }
    BST(Node *n)
    {
        root = n;
    }

    void AddNodeITOPrice(int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
                         int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
                         string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
                         string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-")
    {
        register Node *temp = root;
        Node *ptr = new Node(baths, area_marla, area_sqft, bedrooms,
                             price, latitude, longitude, property_id, location_id,
                             page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent); // 5
                                                                                                                                         //   3     6
        if (root == 0)
        {
            root = ptr;
            // cout << "added as Root" << endl;
            return;
        }
        while (temp != 0)
        {
            if (price == temp->price)
            {
                temp->mid = ptr;
                // cout << "Inserted at mid of : " << temp->price << endl;
                return;
            }
            else if (temp->price > price && temp->left == 0)
            {
                temp->left = ptr;
                // cout << "Inserted at left of : " << temp->price << endl;
                return;
            }
            else if (temp->price < price && temp->right == 0)
            {
                temp->right = ptr;
                // cout << "Inserted at right of : " << temp->price << endl;
                return;
            }
            else if (temp->price > price && temp->left != 0)
            {
                temp = temp->left;
            }
            else if (temp->price < price && temp->right != 0)
            {
                temp = temp->right;
            }
        }
    }
    void AddNodeITOArea_sqft(int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
                             int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
                             string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
                             string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-")
    {
        register Node *temp = root;
        Node *ptr = new Node(baths, area_marla, area_sqft, bedrooms,
                             price, latitude, longitude, property_id, location_id,
                             page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent); // 5
                                                                                                                                         //   3     6
        if (root == 0)
        {
            root = ptr;
            // cout << "added as Root" << endl;
            return;
        }
        while (temp != 0)
        {
            if (area_sqft == temp->area_sqft)
            {
                temp->mid = ptr;
                // cout << "Inserted at mid of : " << temp->area_sqft << endl;
                return;
            }
            else if (temp->area_sqft > area_sqft && temp->left == 0)
            {
                temp->left = ptr;
                // cout << "Inserted at left of : " << temp->area_sqft << endl;
                return;
            }
            else if (temp->area_sqft < area_sqft && temp->right == 0)
            {
                temp->right = ptr;
                // cout << "Inserted at right of : " << temp->area_sqft << endl;
                return;
            }
            else if (temp->area_sqft > area_sqft && temp->left != 0)
            {
                temp = temp->left;
            }
            else if (temp->area_sqft < area_sqft && temp->right != 0)
            {
                temp = temp->right;
            }
        }
    }
    void AddNodeITOBedrooms(int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
                            int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
                            string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
                            string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-")
    {
        register Node *temp = root;
        Node *ptr = new Node(baths, area_marla, area_sqft, bedrooms,
                             price, latitude, longitude, property_id, location_id,
                             page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent); // 5
                                                                                                                                         //   3     6
        if (root == 0)
        {
            root = ptr;
            // cout << "added as Root" << endl;
            return;
        }
        while (temp != 0)
        {
            if (bedrooms == temp->bedrooms)
            {
                temp->mid = ptr;
                // cout << "Inserted at mid of : " << temp->area_sqft << endl;
                return;
            }
            else if (temp->bedrooms > bedrooms && temp->left == 0)
            {
                temp->left = ptr;
                // cout << "Inserted at left of : " << temp->area_sqft << endl;
                return;
            }
            else if (temp->bedrooms < bedrooms && temp->right == 0)
            {
                temp->right = ptr;
                // cout << "Inserted at right of : " << temp->area_sqft << endl;
                return;
            }
            else if (temp->bedrooms > bedrooms && temp->left != 0)
            {
                temp = temp->left;
            }
            else if (temp->bedrooms < bedrooms && temp->right != 0)
            {
                temp = temp->right;
            }
        }
    }
    void Preordertriversal()
    {
        Node *temp = root;
        this->preOrderTri(temp);
        cout << endl;
    }
    void Postordertriversal()
    {
        Node *temp = root;
        this->postOrderTri(temp);
        cout << endl;
    }
    void inOrderTriversal()
    {
        Node *temp = root;
        this->inOrderTri(temp);
        cout << endl;
    }
    // void iterativePreorder()
    // {
    //     if (root == NULL)
    //         return;
    //     Node *temp;
    //     stack<Node *> st;
    //     st.push(root);
    //     while (!st.empty())
    //     {
    //         temp = st.top();
    //         cout << temp->data << "\t";
    //         st.pop();

    //         if (temp->left)
    //             st.push(temp->left);

    //         if (temp->right)
    //             st.push(temp->right);
    //     }
    // }
    Node *search(int val)
    {
        Node *temp = root;
        return recursiveSearch(temp, val);
    }
    // bool isBst()
    // {
    //     Node *r = this->root;
    //     if (this->ifBST(r, 0, 0))
    //         cout << "FAs";
    //     return true;
    //     return false;
    // }
    // void deleteNode(int data)
    // {
    //     Node *temp = root;
    //     this->root = this->delInBST(temp, data);
    // }
    // void truncate(int ll, int ul)
    // {
    //     Node *r = root;
    //     if (root == NULL)
    //         return;
    //     Node *temp;
    //     stack<Node *> st;
    //     st.push(root);
    //     stack<int> stval;
    //     while (!st.empty())
    //     {
    //         temp = st.top();
    //         if (temp->data > ul || temp->data < ll)
    //             stval.push(temp->data);
    //         // cout << temp->data << "\t";

    //         st.pop();

    //         if (temp->left)
    //             st.push(temp->left);

    //         if (temp->right)
    //             st.push(temp->right);
    //     }
    //     int d;
    //     while (!stval.empty())
    //     {
    //         d = stval.top();
    //         stval.pop();
    //         this->deleteNode(d);
    //     }
    // }
    int TreeHeight()
    {
        Node *temp = root;
        return height(temp);
    }

    void matchcalcITOPrice(float divid, Pqueue &queue, int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
                           int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
                           string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
                           string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-")
    {
        register Node *temp = root;
        this->calcITOPrice(divid, temp, queue, baths, area_marla, area_sqft, bedrooms,
                           price, latitude, longitude, property_id, location_id,
                           page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
    }
    void matchcalcITOBedroom(float divid, Pqueue &queue, int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
                             int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
                             string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
                             string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-")
    {
        register Node *temp = root;
        this->calcITOBedrooms(divid, temp, queue, baths, area_marla, area_sqft, bedrooms,
                              price, latitude, longitude, property_id, location_id,
                              page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
    }
    void matchcalcITOSqrFt(float divid, Pqueue &queue, int baths = 0, int area_marla = 0, int area_sqft = 0, int bedrooms = 0, int_fast64_t price = 0,
                           int_fast64_t latitude = 0, int_fast64_t longitude = 0, int_fast64_t property_id = 0, int_fast64_t location_id = 0,
                           string page_url = "-", string property_type = "-", string price_bin = "-", string location = "-", string city = "-",
                           string province_name = "-", string locality = "-", string area = "-", string purpose = "-", string agency = "-", string agent = "-")
    {
        register Node *temp = root;
        this->calcITOSqrFt(divid, temp, queue, baths, area_marla, area_sqft, bedrooms,
                           price, latitude, longitude, property_id, location_id,
                           page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
    }
};
inline float tenPercent(int_fast64_t n)
{
    n = n / 100;
    return n * 10;
}
inline int Numberofdigits(int_fast64_t n)
{
    register int i = 1;
    while (n > 0)
    {
        n /= 10;
        i *= 10;
    }
    return i / 10;
}
inline float matchsub(int_fast64_t a, int_fast64_t b) // 10  200
{
    if (a == b)
        return 100;
    else
    {
        float x = abs(a - b);                          // 10
        float totaldigits = Numberofdigits(max(a, b)); // 100
        float res = x / (totaldigits);
        return 100 - (res * 100);
    }
}
inline string upper_string(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z') // checking for lowercase characters
            str[i] = str[i] - 32;           // converting lowercase to uppercase
    }
    return str;
}
void Load_Tree(BST &KarachiP, BST &LahoreP, BST &IslamabadP, BST &RawalpindiP, BST &FaisalabadP,
               BST &KarachiB, BST &LahoreB, BST &IslamabadB, BST &RawalpindiB, BST &FaisalabadB,
               BST &KarachiSft, BST &LahoreSft, BST &IslamabadSft, BST &RawalpindiSft, BST &FaisalabadSft)
{
    register int baths, area_marla, area_sqft, bedrooms;
    register int_fast64_t price, latitude, longitude, property_id, location_id;
    register string page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent;

    string fname = "zem.csv";
    // cout<<"Enter the file name: ";
    // cin>>fname;

    vector<vector<string>> content;
    vector<string> row;
    string convertToint;
    string line, word;
    fstream file(fname, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);
            // cout<<line<<endl;

            while (getline(str, word, ','))
                row.push_back(word);
            {
                convertToint = row[0];
                stringstream CTI(convertToint);

                CTI >> property_id;
            }
            {
                convertToint = row[1];
                stringstream CTI(convertToint);
                CTI >> location_id;
            }
            page_url = upper_string(row[2]);
            property_type = upper_string(row[3]);
            {
                convertToint = row[4];
                stringstream CTI(convertToint);
                CTI >> price;
            }
            price_bin = upper_string(row[5]);
            location = upper_string(row[6]);
            city = upper_string(row[7]);
            province_name = upper_string(row[8]);
            locality = upper_string(row[9]);
            {
                convertToint = row[10];
                stringstream CTI(convertToint);
                CTI >> latitude;
            }
            {
                convertToint = row[11];
                stringstream CTI(convertToint);
                CTI >> longitude;
            }

            {
                convertToint = row[12];
                stringstream CTI(convertToint);
                CTI >> baths;
            }
            area = upper_string(row[13]);
            {
                convertToint = row[14];
                stringstream CTI(convertToint);
                CTI >> area_marla;
            }
            {
                convertToint = row[15];
                stringstream CTI(convertToint);
                CTI >> area_sqft;
            }
            purpose = upper_string(row[16]);
            {
                convertToint = row[17];
                stringstream CTI(convertToint);
                CTI >> bedrooms;
            }
            agency = upper_string(row[22]);
            agent = upper_string(row[23]);
            if (city == "KARACHI")
            {
                KarachiP.AddNodeITOPrice(baths, area_marla, area_sqft, bedrooms,
                                         price, latitude, longitude, property_id, location_id,
                                         page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
                KarachiB.AddNodeITOBedrooms(baths, area_marla, area_sqft, bedrooms,
                                            price, latitude, longitude, property_id, location_id,
                                            page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
                KarachiSft.AddNodeITOArea_sqft(baths, area_marla, area_sqft, bedrooms,
                                               price, latitude, longitude, property_id, location_id,
                                               page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
            }
            else if (city == "ISLAMABAD")
            {
                IslamabadP.AddNodeITOPrice(baths, area_marla, area_sqft, bedrooms,
                                           price, latitude, longitude, property_id, location_id,
                                           page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
                IslamabadB.AddNodeITOBedrooms(baths, area_marla, area_sqft, bedrooms,
                                              price, latitude, longitude, property_id, location_id,
                                              page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
                IslamabadSft.AddNodeITOArea_sqft(baths, area_marla, area_sqft, bedrooms,
                                                 price, latitude, longitude, property_id, location_id,
                                                 page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
            }
            else if (city == "LAHORE")
            {
                LahoreP.AddNodeITOPrice(baths, area_marla, area_sqft, bedrooms,
                                        price, latitude, longitude, property_id, location_id,
                                        page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
                LahoreB.AddNodeITOBedrooms(baths, area_marla, area_sqft, bedrooms,
                                           price, latitude, longitude, property_id, location_id,
                                           page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
                LahoreSft.AddNodeITOArea_sqft(baths, area_marla, area_sqft, bedrooms,
                                              price, latitude, longitude, property_id, location_id,
                                              page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
            }
            else if (city == "FAISALABAD")
            {
                FaisalabadP.AddNodeITOPrice(baths, area_marla, area_sqft, bedrooms,
                                            price, latitude, longitude, property_id, location_id,
                                            page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
                FaisalabadB.AddNodeITOBedrooms(baths, area_marla, area_sqft, bedrooms,
                                               price, latitude, longitude, property_id, location_id,
                                               page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
                FaisalabadSft.AddNodeITOArea_sqft(baths, area_marla, area_sqft, bedrooms,
                                                  price, latitude, longitude, property_id, location_id,
                                                  page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
            }
            else if (city == "RAWALPINDI")
            {
                RawalpindiP.AddNodeITOPrice(baths, area_marla, area_sqft, bedrooms,
                                            price, latitude, longitude, property_id, location_id,
                                            page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
                RawalpindiB.AddNodeITOBedrooms(baths, area_marla, area_sqft, bedrooms,
                                               price, latitude, longitude, property_id, location_id,
                                               page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
                RawalpindiSft.AddNodeITOArea_sqft(baths, area_marla, area_sqft, bedrooms,
                                                  price, latitude, longitude, property_id, location_id,
                                                  page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent);
            } // cout<<agency  << " " << agent << endl;
        }
    }
    else
        cout << "Could not open the file\n";
}

int main()
{
    char ch = 'Y';
    register Pqueue resultmatch;
    register BST KarachiP, LahoreP, IslamabadP, RawalpindiP, FaisalabadP, KarachiB, LahoreB, IslamabadB, RawalpindiB, FaisalabadB, KarachiSft, LahoreSft, IslamabadSft, RawalpindiSft, FaisalabadSft;
    register int baths, area_marla, area_sqft, bedrooms;
    register int_fast64_t price, latitude, longitude, property_id, location_id;
    register string page_url, property_type, price_bin, location, city, province_name, locality, area, purpose, agency, agent;
    float divider = 0;
    Load_Tree(KarachiP, LahoreP, IslamabadP, RawalpindiP, FaisalabadP, KarachiB, LahoreB, IslamabadB, RawalpindiB, FaisalabadB, KarachiSft, LahoreSft, IslamabadSft, RawalpindiSft, FaisalabadSft);
    cout << endl
         << endl
         << endl
         << endl;
    cout << "loaded" << endl;

    cout << "Welcome To E-state Agency" << endl;

    cout << "Press 0(numeric) -(alphanumeric) if you want the field empty" << endl;

    cout << "Enter location(alphanumeric) : ";
    getline(cin, location);
    location = upper_string(location);
    if (location != "-")
        divider += 100;

    cout << "Enter number of bedrooms(numeric) : ";
    cin >> bedrooms;
    if (bedrooms > 0)
        divider += 100;

    cout << "Enter area in square fit(numeric) : ";
    cin >> area_sqft;
    if (area_sqft > 0)
        divider += 100;

    // cout << "Enter latitude(numeric) : ";
    // cin >> latitude;

    // cout << "Enter longitude(numeric) : ";
    // cin >> longitude;

    cout << "Enter price(numeric) : ";
    cin >> price;
    if (price > 0)
        divider += 100;

    cout << "Enter property type(alphanumeric) e.g (house,flat,upper portion,lower portion ) : ";
    cin >> property_type;
    property_type = upper_string(property_type);
    if (property_type != "-")
        divider += 100;

    cout << "Enter price bin(alphanumeric) e.g(low,medium,high,very high) : ";
    cin.ignore();
    getline(cin, price_bin);
    price_bin = upper_string(price_bin);
    if (price_bin != "-")
        divider += 100;

    cout << "Enter city(alphanumeric) : ";
    cin >> city;
    city = upper_string(city);

    // cout << "Enter province(alphanumeric) : ";
    // cin >> province_name;
    // province_name = upper_string(province_name);

    // cout << "enter Area in kanals(alphanumeric) : ";
    // cin >> area;
    // area = upper_string(area);
    // area += " KANAL";
    if (city == "KARACHI" || city == "-") // price room area
    {
        cout << "RUNNING 1st ALOGORITHIM " << endl;
        cout << "SEARCHING  ";
        KarachiP.matchcalcITOPrice(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                   latitude, longitude, property_id, location_id,
                                   page_url, property_type, price_bin, location, city,
                                   province_name, locality, area, purpose, agency, agent);
        if (resultmatch.NoOfNode() < 5)
        {
            cout << endl
                 << "RUNNING 2nd ALOGORITHIM " << endl
                 << "SEARCHING ";
            KarachiB.matchcalcITOBedroom(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                         latitude, longitude, property_id, location_id,
                                         page_url, property_type, price_bin, location, city,
                                         province_name, locality, area, purpose, agency, agent);
        }
        if (resultmatch.NoOfNode() < 5)
        {
            cout << endl
                 << "RUNNING 3rd ALOGORITHIM " << endl
                 << "SEARCHING ";
            KarachiSft.matchcalcITOSqrFt(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                         latitude, longitude, property_id, location_id,
                                         page_url, property_type, price_bin, location, city,
                                         province_name, locality, area, purpose, agency, agent);
        }
    }
    if (city == "ISLAMABAD" || city == "-")
    {
        cout << endl
             << "RUNNING 1st ALOGORITHIM " << endl
             << "SEARCHING ";
        IslamabadP.matchcalcITOPrice(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                     latitude, longitude, property_id, location_id,
                                     page_url, property_type, price_bin, location, city,
                                     province_name, locality, area, purpose, agency, agent);
        if (resultmatch.NoOfNode() <= 5)
        {
            cout << endl
                 << "RUNNING 2nd ALOGORITHIM " << endl
                 << "SEARCHING ";
            IslamabadB.matchcalcITOBedroom(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                           latitude, longitude, property_id, location_id,
                                           page_url, property_type, price_bin, location, city,
                                           province_name, locality, area, purpose, agency, agent);
        }
        if (resultmatch.NoOfNode() < 5)
        {
            cout << endl
                 << "RUNNING 3rd ALOGORITHIM " << endl
                 << "SEARCHING ";
            IslamabadSft.matchcalcITOSqrFt(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                           latitude, longitude, property_id, location_id,
                                           page_url, property_type, price_bin, location, city,
                                           province_name, locality, area, purpose, agency, agent);
        }
    }
    if (city == "LAHORE" || city == "-")
    {
        cout << endl
             << "RUNNING 1st ALOGORITHIM " << endl
             << "SEARCHING ";
        LahoreP.matchcalcITOPrice(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                  latitude, longitude, property_id, location_id,
                                  page_url, property_type, price_bin, location, city,
                                  province_name, locality, area, purpose, agency, agent);
        if (resultmatch.NoOfNode() <= 5)
        {
            cout << endl
                 << "RUNNING 2nd ALOGORITHIM " << endl
                 << "SEARCHING ";
            LahoreB.matchcalcITOBedroom(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                        latitude, longitude, property_id, location_id,
                                        page_url, property_type, price_bin, location, city,
                                        province_name, locality, area, purpose, agency, agent);
        }
        if (resultmatch.NoOfNode() < 5)
        {
            cout << endl
                 << "RUNNING 3rd ALOGORITHIM " << endl
                 << "SEARCHING ";
            LahoreSft.matchcalcITOSqrFt(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                        latitude, longitude, property_id, location_id,
                                        page_url, property_type, price_bin, location, city,
                                        province_name, locality, area, purpose, agency, agent);
        }
    }
    if (city == "RAWALPINDI" || city == "-")
    {
        cout << endl
             << "RUNNING 1st ALOGORITHIM " << endl
             << "SEARCHING ";
        RawalpindiP.matchcalcITOPrice(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                      latitude, longitude, property_id, location_id,
                                      page_url, property_type, price_bin, location, city,
                                      province_name, locality, area, purpose, agency, agent);
        if (resultmatch.NoOfNode() <= 5)
        {
            cout << endl
                 << "RUNNING 2nd ALOGORITHIM " << endl
                 << "SEARCHING ";
            RawalpindiB.matchcalcITOBedroom(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                            latitude, longitude, property_id, location_id,
                                            page_url, property_type, price_bin, location, city,
                                            province_name, locality, area, purpose, agency, agent);
        }
        if (resultmatch.NoOfNode() < 5)
        {
            cout << endl
                 << "RUNNING 3rd ALOGORITHIM " << endl
                 << "SEARCHING ";
            RawalpindiSft.matchcalcITOSqrFt(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                            latitude, longitude, property_id, location_id,
                                            page_url, property_type, price_bin, location, city,
                                            province_name, locality, area, purpose, agency, agent);
        }
    }
    if (city == "FAISLALABAD" || city == "-")
    {
        cout << endl
             << "RUNNING 1st ALOGORITHIM " << endl
             << "SEARCHING ";
        FaisalabadP.matchcalcITOPrice(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                      latitude, longitude, property_id, location_id,
                                      page_url, property_type, price_bin, location, city,
                                      province_name, locality, area, purpose, agency, agent);
        if (resultmatch.NoOfNode() <= 5)
        {
            cout << endl
                 << "RUNNING 2nd ALOGORITHIM " << endl
                 << "SEARCHING ";
            FaisalabadB.matchcalcITOBedroom(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                            latitude, longitude, property_id, location_id,
                                            page_url, property_type, price_bin, location, city,
                                            province_name, locality, area, purpose, agency, agent);
        }
        if (resultmatch.NoOfNode() < 5)
        {
            cout << endl
                 << "RUNNING 3rd ALOGORITHIM " << endl
                 << "SEARCHING ";
            FaisalabadSft.matchcalcITOSqrFt(divider, resultmatch, baths, area_marla, area_sqft, bedrooms, price,
                                            latitude, longitude, property_id, location_id,
                                            page_url, property_type, price_bin, location, city,
                                            province_name, locality, area, purpose, agency, agent);
        }
    }
    cout << endl;
    resultmatch.triversal();
    if (resultmatch.NoOfNode() <= 0)
    {
        cout << "No result found" << endl;
        return 0;
    }
    bool moredetails = true;
    while (moredetails)
    {
        cout << endl
             << "Enter Property ID to find more (0 for exit) : ";
        cin >> property_id;
        resultmatch.MoreDetails(property_id);
        moredetails = property_id;
    }

    cout << endl
         << "Press Y/N to veiw Comparision Graph : ";
    cin >> ch;
    ch = toupper(ch);
    if (ch == 'Y')
        resultmatch.Graph();

    cout << "Press Y/N to Find distance from your location to property locations : ";
    cin >> ch;
    ch = toupper(ch);
    if (ch == 'Y')
        system("Python distance.py ok go");
    remove("graphfile.txt");
    remove("result.txt");
    remove("stringmatch.txt");
    return 0;
}