/* -----------------------------------------------------------------------------
 * Rule_FWS.cpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Dec 31 10:33:28 CET 2017
 *
 * -----------------------------------------------------------------------------
 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Rule_FWS.hpp"
#include "Visitor.hpp"
#include "ParserContext.hpp"

#include "Rule_WSP.hpp"
#include "Rule_obs_FWS.hpp"
#include "Rule_CRLF.hpp"

using namespace abnf;

Rule_FWS::Rule_FWS(
  const string& spelling, 
  const vector<const Rule*>& rules) : Rule(spelling, rules)
{
}

Rule_FWS::Rule_FWS(const Rule_FWS& rule) : Rule(rule)
{
}

Rule_FWS& Rule_FWS::operator=(const Rule_FWS& rule)
{
  Rule::operator=(rule);
  return *this;
}

const Rule_FWS* Rule_FWS::clone() const
{
  return new Rule_FWS(this->spelling, this->rules);
}

void* Rule_FWS::accept(Visitor& visitor) const
{
  return visitor.visit(this);
}

const Rule_FWS* Rule_FWS::parse(ParserContext& context)
{
  context.push("FWS");

  bool parsed = true;
  int s0 = context.index;
  vector<const Rule*> e0;
  const Rule* rule;

  parsed = false;
  if (!parsed)
  {
    {
      vector<const Rule*> e1;
      int s1 = context.index;
      parsed = true;
      if (parsed)
      {
        bool f1 = true;
        int c1 = 0;
        for (int i1 = 0; i1 < 1 && f1; i1++)
        {
          unsigned int g1 = context.index;
          parsed = false;
          if (!parsed)
          {
            {
              vector<const Rule*> e2;
              int s2 = context.index;
              parsed = true;
              if (parsed)
              {
                bool f2 = true;
                int c2 = 0;
                for (int i2 = 0; i2 < 1 && f2; i2++)
                {
                  unsigned int g2 = context.index;
                  parsed = false;
                  if (!parsed)
                  {
                    {
                      vector<const Rule*> e3;
                      int s3 = context.index;
                      parsed = true;
                      if (parsed)
                      {
                        bool f3 = true;
                        int c3 = 0;
                        for (int i3 = 0; f3; i3++)
                        {
                          rule = Rule_WSP::parse(context);
                          if ((f3 = rule != NULL))
                          {
                            e3.push_back(rule);
                            c3++;
                          }
                        }
                        parsed = true;
                      }
                      if (parsed)
                      {
                        bool f3 = true;
                        int c3 = 0;
                        for (int i3 = 0; i3 < 1 && f3; i3++)
                        {
                          rule = Rule_CRLF::parse(context);
                          if ((f3 = rule != NULL))
                          {
                            e3.push_back(rule);
                            c3++;
                          }
                        }
                        parsed = c3 == 1;
                      }
                      if (parsed)
                        e2.insert(e2.end(), e3.begin(), e3.end());
                      else
                        context.index = s3;
                    }
                  }
                  if (context.index > g2) c2++;
                  f2 = c2 > i2;
                }
                parsed = true;
              }
              if (parsed)
              {
                bool f2 = true;
                int c2 = 0;
                for (int i2 = 0; i2 < 1 && f2; i2++)
                {
                  rule = Rule_WSP::parse(context);
                  if ((f2 = rule != NULL))
                  {
                    e2.push_back(rule);
                    c2++;
                  }
                }
                for (int i2 = 0; f2; i2++)
                {
                  rule = Rule_WSP::parse(context);
                  if ((f2 = rule != NULL))
                  {
                    e2.push_back(rule);
                    c2++;
                  }
                }
                parsed = c2 >= 1;
              }
              if (parsed)
                e1.insert(e1.end(), e2.begin(), e2.end());
              else
                context.index = s2;
            }
          }
          if (context.index > g1) c1++;
          f1 = c1 > i1;
        }
        parsed = c1 == 1;
      }
      if (parsed)
        e0.insert(e0.end(), e1.begin(), e1.end());
      else
        context.index = s1;
    }
  }
  if (!parsed)
  {
    {
      vector<const Rule*> e1;
      int s1 = context.index;
      parsed = true;
      if (parsed)
      {
        bool f1 = true;
        int c1 = 0;
        for (int i1 = 0; i1 < 1 && f1; i1++)
        {
          rule = Rule_obs_FWS::parse(context);
          if ((f1 = rule != NULL))
          {
            e1.push_back(rule);
            c1++;
          }
        }
        parsed = c1 == 1;
      }
      if (parsed)
        e0.insert(e0.end(), e1.begin(), e1.end());
      else
        context.index = s1;
    }
  }

  rule = NULL;
  if (parsed)
    rule = new Rule_FWS(context.text.substr(s0, context.index - s0), e0);
  else
    context.index = s0;

  context.pop("FWS", parsed);

  return (Rule_FWS*)rule;
}

/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */