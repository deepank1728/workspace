#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int main()
{
    string key="00001000011001010110110001101100011011110111011101101111011100100110110001100100";
    //string key = "11011100011011110011111101011001";
            char[] p1, p2, p3, p4;
            char[] sbkey1 = new char[4], sbkey2 = new char[4], sbkey3 = new char[4], sbkey4 = new char[4], sbkey5 = new char[4], sbkey6 = new char[4];
            char[] r1 = new char[4], r2 = new char[4], r3 = new char[4], r4 = new char[4];
            char[] rk1 = new char[4], rk2 = new char[4], rk3 = new char[4], rk4 = new char[4];
            char[] rr1 = new char[4], rr2 = new char[4], rr3 = new char[4], rr4 = new char[4], rr5 = new char[4], rr6 = new char[4], rr7 = new char[4];
            char[] k11 = key.ToCharArray(0, 4), k12 = key.ToCharArray(4, 4), k13 = key.ToCharArray(8, 4), k14 = key.ToCharArray(12, 4), k15 = key.ToCharArray(16, 4), k16 = key.ToCharArray(20, 4);
            char[] k21 = key.ToCharArray(24, 4), k22 = key.ToCharArray(28, 4), k23 = key.ToCharArray(6, 4), k24 = key.ToCharArray(10, 4), k25 = key.ToCharArray(14, 4), k26 = key.ToCharArray(18, 4);
            char[] k31 = key.ToCharArray(22, 4), k32 = key.ToCharArray(26, 4), k33 = key.ToCharArray(30, 2), k34 = key.ToCharArray(2, 4), k35 = key.ToCharArray(12, 4), k36 = key.ToCharArray(16, 4);
            char[] optrns1 = key.ToCharArray(18, 4), optrns2 = key.ToCharArray(22, 4), optrns3 = key.ToCharArray(26, 4), optrns4 = key.ToCharArray(30, 2);
            char[] comb = key.ToCharArray(0, 2);
            string comb1 = new string(k33);
            string comb2 = new string(comb);
            comb1 = comb1 + comb2;
            k33 = comb1.ToCharArray();
            char[] k41 = key.ToCharArray(20, 4), k42 = key.ToCharArray(24, 4), k43 = key.ToCharArray(28, 4), k44 = key.ToCharArray(0, 4), k45 = key.ToCharArray(4, 4), k46 = key.ToCharArray(8, 4); ;
            comb = key.ToCharArray(0, 2);
            comb1 = new string(optrns4);
            comb2 = new string(comb);
            comb1 = comb1 + comb2;
            optrns4 = comb1.ToCharArray();
            int len1;
            string doc2 = null;
            int z;
            string sss = null;

            for (int eight_round = 0; eight_round < 4; eight_round++)
            {
                if (eight_round == 0)
                {
                    sbkey1 = k11;
                    sbkey2 = k12;
                    sbkey3 = k13;
                    sbkey4 = k14;
                    sbkey5 = k15;
                    sbkey6 = k16;
                }
                if (eight_round == 1)
                {
                    sbkey1 = k21;
                    sbkey2 = k22;
                    sbkey3 = k23;
                    sbkey4 = k24;
                    sbkey5 = k25;
                    sbkey6 = k26;
                }
                if (eight_round == 2)
                {
                    sbkey1 = k31;
                    sbkey2 = k32;
                    sbkey3 = k33;
                    sbkey4 = k34;
                    sbkey5 = k35;
                    sbkey6 = k36;
                }
                if (eight_round == 3)
                {
                    sbkey1 = k41;
                    sbkey2 = k42;
                    sbkey3 = k43;
                    sbkey4 = k44;
                    sbkey5 = k45;
                    sbkey6 = k46;
                }
/*
After the generation of sub keys main process begins in which we have to implement 14 steps in each round with the help of six sub keys and 16-bit plain text which we are going to divide in four 4-bit plain text which is represented as X1, X2, X3 and X4. The steps are as following.


1. Multiply X1 and the first sub key Z1.
2. Add X2 and the second sub key Z2.
3. Add X3 and the third sub key Z3.
4. Multiply X4 and the fourth sub key Z4.
5. Bitwise XOR the results of steps 1 and 3.
6. Bitwise XOR the results of steps 2 and 4.
7. Multiply the result of step 5 and the fifth sub key Z5.
8. Add the results of steps 6 and 7.
9. Multiply the result of step 8 and the sixth sub key Z6.
10. Add the results of steps 7 and 9.
11. Bitwise XOR the results of steps 1 and 9.
12. Bitwise XOR the results of steps 3 and 9.
13. Bitwise XOR the results of steps 2 and 10.
14. Bitwise XOR the results of steps 4 and 10.


*/
                doc2 = richTextBox1.Text;
                len1 = doc2.Length;
                richTextBox1.Text = "";
                z = 0;
                while (z < len1)
                {
                    p1 = doc2.ToCharArray(z, 4);
                    p2 = doc2.ToCharArray(z + 4, 4);
                    p3 = doc2.ToCharArray(z + 8, 4);
                    p4 = doc2.ToCharArray(z + 12, 4);

                    {
                        string aa, bb, cc = null;
                        int l1;
                        int total;
                        aa = new string(p1);
                        bb = new string(sbkey1);
                        l1 = aa.Length;
                        int a1, b, res, c = 3;
                        a1 = Convert.ToInt32(aa, 2);
                        b = Convert.ToInt32(bb, 2);
                        if (a1 == 0)
                        {
                            a1 = 16;
                        }
                        if (b == 0)
                        {
                            b = 16;
                        }
                        total = a1 * b;
                        string[] trr = { "0", "0", "0", "0" };
                        if (total > 16)
                        {
                            total = total%17;
/*
STEP 1 = Multiply X1 and the first sub key Z1.here X1 is the fist four bits of plain text and Z1 is sub key here I multiply the two
binary number by converting them in decimal digit and multiply them and getting the final output convert it again in binary.
The addition for binary no is also done same as above first convert
it in decimal and then after getting final answer reconvert it in binary.


   */                     }
                        if (total != 16)
                        {
                            while (total > 0)
                            {

                                trr[c] = (total % 2).ToString();
                                total = total / 2;
                                c--;

                            }
                        }
                        for (int f = 0; f < 4; f++)
                        {
                            r1[f] = trr[f][0];
                        }
                    }


                    {
                        string aa, bb, cc = null;
                        int l1;
                        int total;
                        aa = new string(p4);
                        bb = new string(sbkey4);
                        l1 = aa.Length;
                        int a1, b, res, c = 3;
                        a1 = Convert.ToInt32(aa, 2);
                        b = Convert.ToInt32(bb, 2);
                        if (a1 == 0)
                        {
                            a1 = 16;
                        }
                        if (b == 0)
                        {
                            b = 16;
                        }
                        total = a1 * b;
                        string[] trr = { "0", "0", "0", "0" };
                        if (total > 16)
                        {
                            total = total % 17;
                        }
                        if (total != 16)
                        {
                            while (total > 0)
                            {

                                trr[c] = (total % 2).ToString();
                                total = total / 2;
                                c--;

                            }
                        }
                        for (int f = 0; f < 4; f++)
                        {
                            r4[f] = trr[f][0];
                        }

                    }

                    {
                        string aa, bb, cc = null;
                        int l1;
                        int total;
                        aa = new string(p2);
                        bb = new string(sbkey2);
                        l1 = aa.Length;
                        int a1, b, res, c = 3;
                        a1 = Convert.ToInt32(aa, 2);
                        b = Convert.ToInt32(bb, 2);
                        total = a1 + b;
                        if (total>15)
              //ADD
                        {
                            total = total % 16;
                        }
                        string[] trr = { "0", "0", "0", "0" };
                        while (total > 0)
                        {
                            trr[c] = (total % 2).ToString();
                            total = total / 2;
                            c--;
                        }
                        for (int f = 0; f < 4; f++)
                        {
                            r2[f] = trr[f][0];
                        }

                    }


                    {
                        string aa, bb, cc = null;
                        int l1;
                        int total;
                        aa = new string(p3);
                        bb = new string(sbkey3);
                        l1 = aa.Length;
                        int a1, b, res, c = 3;
                        a1 = Convert.ToInt32(aa, 2);
                        b = Convert.ToInt32(bb, 2);
                        total = a1 + b;
                        if (total > 15)
                        {
                            total = total % 16;
                        }
                        string[] trr = { "0", "0", "0", "0" };
                        while (total > 0)
                        {
                            trr[c] = (total % 2).ToString();
                            total = total / 2;
                            c--;
                        }
                        for (int f = 0; f < 4; f++)
                        {
                            r3[f] = trr[f][0];
                        }

                    }

/*

End of Top FOUR step of round Now step 5 and 6
Bitwise XOR the results of steps 1 and 3.
Bitwise XOR the results of steps 2 and 4.

*/
                    for (int l = 0; l < 4; l++)
                    {
                        {
                            if ((r1[l] == '0' && r3[l] == '0') || (r1[l] == '1' && r3[l] == '1'))
                            {
                                rr1[l] = '0';
                            }
                            else
                            {
                                rr1[l] = '1';
                            }
                        }
                        {
                            if ((r2[l] == '0' && r4[l] == '0') || (r2[l] == '1' && r4[l] == '1'))
                            {
                                rr2[l] = '0';
                            }
                            else
                            {
                                rr2[l] = '1';
                            }
                        }
                    }

                    // step  7
                    {
                        string aa, bb, cc = null;
                        int l1;
                        int total;
                        aa = new string(rr1);
                        bb = new string(sbkey5);
                        l1 = aa.Length;
                        int a1, b, res, c = 3;
                        a1 = Convert.ToInt32(aa, 2);
                        b = Convert.ToInt32(bb, 2);
                        if (a1 == 0)
                        {
                            a1 = 16;
                        }
                        if (b == 0)
                        {
                            b = 16;
                        }
                        total = a1 * b;
                        if (total > 16)
                        {
                            total = total % 17;
                        }
                        string[] trr = { "0", "0", "0", "0" };
                        if (total != 16)
                        {
                            while (total > 0)
                            {
                                trr[c] = (total % 2).ToString();
                                total = total / 2;
                                c--;
                            }
                        }
                        for (int f = 0; f < 4; f++)
                        {
                            rr3[f] = trr[f][0];
                        }

                    }

                    //step 8
                    {
                        string aa, bb, cc = null;
                        int l1;
                        int total;
                        aa = new string(rr3);
                        bb = new string(rr2);
                        l1 = aa.Length;
                        int a1, b, res, c = 3;
                        a1 = Convert.ToInt32(aa, 2);
                        b = Convert.ToInt32(bb, 2);
                        total = a1 + b;
                        if (total > 15)
                        {
                            total = total % 16;
                        }
                        string[] trr = { "0", "0", "0", "0" };
                        while (total > 0)
                        {
                            trr[c] = (total % 2).ToString();
                            total = total / 2;
                            c--;
                        }
                        for (int f = 0; f < 4; f++)
                        {
                            rr4[f] = trr[f][0];
                        }

                    }

                    //ste 9
                    {
                        string aa, bb, cc = null;
                        int l1;
                        int total;
                        aa = new string(rr4);
                        bb = new string(sbkey6);
                        l1 = aa.Length;
                        int a1, b, res, c = 3;
                        a1 = Convert.ToInt32(aa, 2);
                        b = Convert.ToInt32(bb, 2);
                        if (a1 == 0)
                        {
                            a1 = 16;
                        }
                        if (b == 0)
                        {
                            b = 16;
                        }
                        total = a1 * b;
                        if (total > 16)
                        {
                            total = total % 17;
                        }
                        string[] trr = { "0", "0", "0", "0" };
                        if (total != 16)
                        {
                            while (total > 0)
                            {
                                trr[c] = (total % 2).ToString();
                                total = total / 2;
                                c--;
                            }
                        }
                        for (int f = 0; f < 4; f++)
                        {
                            rr5[f] = trr[f][0];
                        }

                    }

                    //step 10
                    {
                        string aa, bb, cc = null;
                        int l1;
                        int total;
                        aa = new string(rr3);
                        bb = new string(rr5);
                        l1 = aa.Length;
                        int a1, b, res, c = 3;
                        a1 = Convert.ToInt32(aa, 2);
                        b = Convert.ToInt32(bb, 2);
                        total = a1 + b;
                        if (total > 15)
                        {
                            total = total % 16;
                        }
                        string[] trr = { "0", "0", "0", "0" };
                        while (total > 0)
                        {
                            trr[c] = (total % 2).ToString();
                            total = total / 2;
                            c--;
                        }
                        for (int f = 0; f < 4; f++)
                        {
                            rr6[f] = trr[f][0];
                        }

                    }

                    // step 11 && 12
                    for (int l = 0; l < 4; l++)
                    {
                        {
                            if ((rr5[l] == '0' && r1[l] == '0') || (r1[l] == '1' && rr5[l] == '1'))
                            {
                                rk1[l] = '0';
                            }
                            else
                            {
                                rk1[l] = '1';
                            }
                        }
                        {
                            if ((rr6[l] == '0' && r4[l] == '0') || (r4[l] == '1' && rr6[l] == '1'))
                            {
                                rk4[l] = '0';
                            }
                            else
                            {
                                rk4[l] = '1';
                            }
                        }

                    }
                    // step 13 && 14
                    for (int l = 0; l < 4; l++)
                    {

                        {
                            if ((rr6[l] == '0' && r2[l] == '0') || (r2[l] == '1' && rr6[l] == '1'))
                            {
                                rk3[l] = '0';
                            }
                            else
                            {
                                rk3[l] = '1';
                            }
                        }
                        {
                            if ((rr5[l] == '0' && r3[l] == '0') || (r3[l] == '1' && rr5[l] == '1'))
                            {
                                rk2[l] = '0';
                            }
                            else
                            {
                                rk2[l] = '1';
                            }
                        }
                    }


                    sss = new string(rk1);
                    richTextBox1.AppendText(sss);
                    sss = new string(rk3);
                    richTextBox1.AppendText(sss);
                    sss = new string(rk2);
                    richTextBox1.AppendText(sss);
                    sss = new string(rk4);
                    richTextBox1.AppendText(sss);

                    z = z + 16;
                }
            }
/*
Now all the 14 steps are over but we have to apply output
transformation on the final answer and in the final transformation
we have to apply first four steps again.

    */        doc2 = richTextBox1.Text;
            len1 = doc2.Length;
            richTextBox1.Text = "";
            z = 0;
            while (z < len1)
            {
                p1 = doc2.ToCharArray(z, 4);
                p2 = doc2.ToCharArray(z + 4, 4);
                p3 = doc2.ToCharArray(z + 8, 4);
                p4 = doc2.ToCharArray(z + 12, 4);

                {
                    string aa, bb, cc = null;
                    int l1;
                    int total;
                    aa = new string(p1);
                    bb = new string(optrns1);
                    l1 = aa.Length;
                    int a1, b, res, c = 3;
                    a1 = Convert.ToInt32(aa, 2);
                    b = Convert.ToInt32(bb, 2);
                    if (a1 == 0)
                    {
                        a1 = 16;
                    }
                    if (b == 0)
                    {
                        b = 16;
                    }
                    total = a1 * b;
                    string[] trr = { "0", "0", "0", "0" };
                    if (total > 16)
                    {
                        total = total % 17;                         //STEP 1 OF ROUND

                    }
                    if (total != 16)
                    {
                        while (total > 0)
                        {

                            trr[c] = (total % 2).ToString();
                            total = total / 2;
                            c--;

                        }
                    }
                    for (int f = 0; f < 4; f++)
                    {
                        r1[f] = trr[f][0];
                    }
                }


                {
                    string aa, bb, cc = null;
                    int l1;
                    int total;
                    aa = new string(p4);
                    bb = new string(optrns4);
                    l1 = aa.Length;
                    int a1, b, res, c = 3;
                    a1 = Convert.ToInt32(aa, 2);
                    b = Convert.ToInt32(bb, 2);
                    if (a1 == 0)
                    {
                        a1 = 16;
                    }
                    if (b == 0)
                    {
                        b = 16;
                    }
                    total = a1 * b;
                    string[] trr = { "0", "0", "0", "0" };
                    if (total > 16)
                    {
                        total = total % 17;
                    }
                    if (total != 16)
                    {
                        while (total > 0)
                        {

                            trr[c] = (total % 2).ToString();
                            total = total / 2;
                            c--;

                        }
                    }
                    for (int f = 0; f < 4; f++)
                    {
                        r4[f] = trr[f][0];
                    }

                }

                {
                    string aa, bb, cc = null;
                    int l1;
                    int total;
                    aa = new string(p2);
                    bb = new string(optrns2);
                    l1 = aa.Length;
                    int a1, b, res, c = 3;
                    a1 = Convert.ToInt32(aa, 2);
                    b = Convert.ToInt32(bb, 2);
                    total = a1 + b;
                    if (total>15)                                     //ADD
                    {
                        total = total % 16;
                    }
                    string[] trr = { "0", "0", "0", "0" };
                    while (total > 0)
                    {
                        trr[c] = (total % 2).ToString();
                        total = total / 2;
                        c--;
                    }
                    for (int f = 0; f < 4; f++)
                    {
                        r2[f] = trr[f][0];
                    }

                }


                {
                    string aa, bb, cc = null;
                    int l1;
                    int total;
                    aa = new string(p3);
                    bb = new string(optrns3);
                    l1 = aa.Length;
                    int a1, b, res, c = 3;
                    a1 = Convert.ToInt32(aa, 2);
                    b = Convert.ToInt32(bb, 2);
                    total = a1 + b;
                    if (total > 15)
                    {
                        total = total % 16;
                    }
                    string[] trr = { "0", "0", "0", "0" };
                    while (total > 0)
                    {
                        trr[c] = (total % 2).ToString();
                        total = total / 2;
                        c--;
                    }
                    for (int f = 0; f < 4; f++)
                    {
                        r3[f] = trr[f][0];
                    }

                }
                sss = new string(r1);
                richTextBox1.AppendText(sss);
                sss = new string(r2);
                richTextBox1.AppendText(sss);
                sss = new string(r3);
                richTextBox1.AppendText(sss);
                sss = new string(r4);
                richTextBox1.AppendText(sss);
                z = z + 16;
            }

}
