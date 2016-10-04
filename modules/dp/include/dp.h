/***************************************************************************
 *   Copyright (C) 2016 by Ícaro Magalhães and Marcello Marques
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file dp.h
 *   \author Ícaro Lima Magalhães <icaro.lmag@gmail.com>
 *   \author Marcello Marques
 *
 ***************************************************************************/

#ifndef DP_H
#define DP_H

#include <iostream>
#include <string>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>

namespace compendium
{

    /**
     * \brief TODO brief content
     */
    class DP
    {

    public:

        static int binary_knapsack(int W, std::vector< std::pair<int, int> > &sack, int n);

        /*
            dp[i][j]
            means: change i with 0:j coins
        */
        static int coin_change(int cents, int* coins, int s)
        {
            if(cents <= 0) return 0;

            int **dp;
            dp = new int*[cents+1];
            for (int i = 0; i < cents + 1; i++)
            {
                dp[i] = new int[s];
            }

            for (int i = 0; i < s; i++)
            {
                dp[0][i] = 1;
            }


            for (int i = 1; i <= cents; i++)
            {
                for (int j = 0; j < s; j++)
                {
                    int with_j = (((i - coins[j]) >= 0) ? dp[i-coins[j]][j] : 0);
                    int without_j = ((j > 0 ? dp[i][j-1] : 0 ));
                    dp[i][j] = without_j + with_j;
                }
            }

            return dp[cents][s-1];

        }


        // TODO fix word break
        /*
        static bool dict_contains(std::string word, const std::string *&dictionary, const int dict_size) const
        {
            for (int i = 0; i < dict_size; i++)
                if (dictionary[i] == word)
                   return true;
            return false;
        }

        static bool wordBreak(std::string str, const std::string *&dictionary, const int dict_size)
        {
            int size = str.size();
            if (size == 0) return true;

            bool piece[size+1]; // 1 if str[0..i-1] is in dictionary
            std::memset(piece, 0, sizeof(piece));

            for (int i = 1; i <= size; i++)
            {
                if (piece[i] == false && dict_contains(str.substr(0, i)), dictionary, dict_size)
                {
                    piece[i] = true; //if piece[i] == true we dont need check
                }

                if (piece[i] == true)
                {
                    if (i == size)
                    {
                        return true; //the complete word
                    }

                    for (int j = i+1; j <= size; j++)
                    {
                        if (piece[j] == false && dict_contains(str.substr(i, j-i)), dictionary, dict_size)
                        {
                            piece[j] = true; //same check, but now in the remains
                        }

                        if (j == size && piece[j] == true)
                        {
                            return true; //last character
                        }
                    }
                }
            }

            return false;
        }
        */


        // BINCOEF
        static int binomialCoefficient(int n, int k)
        {
            int dp[n+1][k+1];

            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= std::min(k, n); j++) //k > n doesn't make sense
                {
                    if (i == 0 || j == 0 || j == i) //C(i, 0) = C(i, i) = 1 : base case
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; //recursion on table
                    }
                }
            }

            return dp[n][k];
        }



    };

}

#endif // DP_H