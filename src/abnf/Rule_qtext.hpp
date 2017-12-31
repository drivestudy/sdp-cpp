/* -----------------------------------------------------------------------------
 * Rule_qtext.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.2
 * Produced : Sun Dec 31 10:33:28 CET 2017
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_qtext_hpp
#define Rule_qtext_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_qtext : public Rule
{
public:
  Rule_qtext(const std::string& spelling, const std::vector<const Rule*>& rules);
  Rule_qtext(const Rule_qtext& rule);

  Rule_qtext& operator=(const Rule_qtext& rule);

  const Rule_qtext* clone(void) const;

  static const Rule_qtext* parse(ParserContext& context);

  void* accept(Visitor& visitor) const;
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */