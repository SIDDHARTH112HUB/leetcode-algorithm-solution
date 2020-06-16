[770.basic-calculator-iv](https://leetcode.com/problems/basic-calculator-iv/)  

Given an `expression` such as `expression = "e + 8 - a + 5"` and an evaluation map such as `{"e": 1}` (given in terms of `evalvars = ["e"]` and `evalints = [1]`), return a list of tokens representing the simplified expression, such as `["-1*a","14"]`

*   An expression alternates chunks and symbols, with a space separating each chunk and symbol.
*   A chunk is either an expression in parentheses, a variable, or a non-negative integer.
*   A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters, and note that variables never have a leading coefficient or unary operator like `"2x"` or `"-x"`.

Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction. For example, `expression = "1 + 2 * 3"` has an answer of `["7"]`.

The format of the output is as follows:

*   For each term of free variables with non-zero coefficient, we write the free variables within a term in sorted order lexicographically. For example, we would never write a term like `"b*a*c"`, only `"a*b*c"`.
*   Terms have degree equal to the number of free variables being multiplied, counting multiplicity. (For example, `"a*a*b*c"` has degree 4.) We write the largest degree terms of our answer first, breaking ties by lexicographic order ignoring the leading coefficient of the term.
*   The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables (if they exist.)  A leading coefficient of 1 is still printed.
*   An example of a well formatted answer is `["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"]` 
*   Terms (including constant terms) with coefficient 0 are not included.  For example, an expression of "0" has an output of \[\].

**Examples:**

  
**Input:** expression = "e + 8 - a + 5", evalvars = \["e"\], evalints = \[1\]
  
**Output:** \["-1\*a","14"\]
  

  
**Input:** expression = "e - 8 + temperature - pressure",
  
evalvars = \["e", "temperature"\], evalints = \[1, 12\]
  
**Output:** \["-1\*pressure","5"\]
  

  
**Input:** expression = "(e + 8) \* (e - 8)", evalvars = \[\], evalints = \[\]
  
**Output:** \["1\*e\*e","-64"\]
  

  
**Input:** expression = "7 - 7", evalvars = \[\], evalints = \[\]
  
**Output:** \[\]
  

  
**Input:** expression = "a \* b \* c + b \* a \* c \* 4", evalvars = \[\], evalints = \[\]
  
**Output:** \["5\*a\*b\*c"\]
  

  
**Input:** expression = "((a - b) \* (b - c) + (c - a)) \* ((a - b) + (b - c) \* (c - a))",
  
evalvars = \[\], evalints = \[\]
  
**Output:** \["-1\*a\*a\*b\*b","2\*a\*a\*b\*c","-1\*a\*a\*c\*c","1\*a\*b\*b\*b","-1\*a\*b\*b\*c","-1\*a\*b\*c\*c","1\*a\*c\*c\*c","-1\*b\*b\*b\*c","2\*b\*b\*c\*c","-1\*b\*c\*c\*c","2\*a\*a\*b","-2\*a\*a\*c","-2\*a\*b\*b","2\*a\*c\*c","1\*b\*b\*b","-1\*b\*b\*c","1\*b\*c\*c","-1\*c\*c\*c","-1\*a\*a","1\*a\*b","1\*a\*c","-1\*b\*c"\]
  

**Note:**

1.  `expression` will have length in range `[1, 250]`.
2.  `evalvars, evalints` will have equal lengths in range `[0, 100]`.  



**Solution:**  

```cpp
class Poly {
private:
    map<list<string>, int> coeffs;
public:
    void update(list<string> key, int val) {
        coeffs[key] += val;
    }
    
    Poly add(Poly& that) {
        Poly ans;
        for (auto& m : this->coeffs) {
            ans.update(m.first, m.second);
        }
        for (auto& m : that.coeffs) {
            ans.update(m.first, m.second);
        }
        return ans;
    }
    
    Poly sub(Poly& that) {
        Poly ans;
        for (auto& m : this->coeffs) {
            ans.update(m.first, m.second);
        }
        for (auto& m : that.coeffs) {
            ans.update(m.first, -m.second);
        }
        return ans;
    }
    
    Poly mul(Poly& that) {
        Poly ans;
        for (auto& m1 : this->coeffs) {
            for (auto& m2 : that.coeffs) {
                list<string> newKey;
                for (string s : m1.first) {
                    newKey.push_back(s);
                }
                for (string s : m2.first) {
                    newKey.push_back(s);
                }
                newKey.sort();
                ans.update(newKey, m1.second * m2.second);
            }
        }
        return ans;
    }
    
    Poly evaluate(map<string, int>& evalMap) {
        Poly ans;
        for (auto& m : this->coeffs) {
            int c = m.second;
            list<string> k;
            for (string s : m.first) {
                if (evalMap.find(s) != evalMap.end()) {
                    c *= evalMap[s];
                } else {
                    k.push_back(s);
                }
            }
            ans.update(k, c);
        }
        return ans;
    }
    
    vector<string> toVector() {
        vector<string> ans;
        vector<list<string>> keys;
        for (auto& m : this->coeffs) {
            if (m.second == 0)
                continue;
            keys.push_back(m.first);
        }
        
        sort(keys.begin(), keys.end(), [](list<string>& a, list<string>& b) -> bool {
            if (a.size() != b.size()) {
                return (a.size() > b.size());
            } else {
                auto ita = a.begin();
                auto itb = b.begin();
                while ((ita != a.end()) && (*ita == *itb)) {
                    ++ita;
                    ++itb;
                }
                return (*ita < *itb);
            }
        });
        
        for (list<string>& k : keys) {
            string w = to_string(this->coeffs[k]);
            for (string s : k) {
                w.push_back('*');
                w.append(s);
            }
            ans.push_back(w);
        }
        return ans;
    }
};

class Solution {
public:
    Poly make(string expr) {
        Poly ans;
        list<string> k;
        if (isdigit(expr[0])) {
            ans.update(k, stoi(expr));
        } else {
            k.push_back(expr);
            ans.update(k, 1);
        }
        return ans;
    }

    Poly combine(Poly& left, Poly& right, char symbol) {
        if (symbol == '+') {
            return left.add(right);
        } else if (symbol == '-') {
            return left.sub(right);
        } else if (symbol == '*') {
            return left.mul(right);
        } else {
            throw "unexpected symbol";
        }    
    }

    Poly parse(string expr) {
        vector<Poly> bucket;
        vector<char> symbols;
        int i = 0;
        while (i < expr.size()) {
            if (expr[i] == '(') {
                int c = 0;
                int j = i;
                for (; j < expr.size(); ++j) {
                    if (expr[j] == '(') {
                        ++c;
                    } else if (expr[j] == ')') {
                        --c;
                    }
                    if (c == 0) {
                        break;
                    }
                }
                bucket.push_back(parse(expr.substr(i + 1, j - i - 1)));
                i = j;
            } else if (isdigit(expr[i]) || isalpha(expr[i])) {
                int j = i;
                for (; j < expr.size(); ++j) {
                    if (expr[j] == ' ') {
                        break;
                    }
                }
                bucket.push_back(make(expr.substr(i, j - i)));
                i = j;
            } else if (expr[i] != ' ') {
                symbols.push_back(expr[i]);
            }
            ++i;
        }

        for (int j = symbols.size() - 1; j >= 0; --j) {
            if (symbols[j] == '*') {
                bucket[j] = combine(bucket[j], bucket[j + 1], '*');
                bucket.erase(bucket.begin() + j + 1);
                symbols.erase(symbols.begin() + j);
            }
        }

        if (bucket.empty()) {
            return Poly();
        }
        Poly ans = bucket[0];
        for (int j = 0; j < symbols.size(); ++j) {
            ans = combine(ans, bucket[j + 1], symbols[j]);
        }

        return ans;
    }

    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        map<string, int> evalMap;
        for (int i = 0; i < evalvars.size(); ++i) {
            evalMap[evalvars[i]] = evalints[i];
        }

        return parse(expression).evaluate(evalMap).toVector();
    }
};
```
      