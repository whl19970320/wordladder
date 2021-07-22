//
//  Copyright UNSW Sydney School of Computer Science and Engineering
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include "comp6771/word_ladder.hpp"

#include <string>
#include <vector>

#include "catch2/catch.hpp"
// When there are very few word ladders between two words.
// I calculated the result from the previous version of the code.
TEST_CASE("hate -> love") {
	// auto const english_lexicon = word_ladder::read_lexicon("./test/word_ladder/english.txt");
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");
	auto const ladders = word_ladder::generate("hate", "love", english_lexicon);

	CHECK(std::size(ladders) == 3);
	// find if the result is sorted
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(),
	                 ladders.end(),
	                 std::vector<std::string>{"hate", "have", "hove", "love"})
	      == 1);
	CHECK(std::count(ladders.begin(),
	                 ladders.end(),
	                 std::vector<std::string>{"hate", "have", "lave", "love"})
	      == 1);
	CHECK(std::count(ladders.begin(),
	                 ladders.end(),
	                 std::vector<std::string>{"hate", "late", "lave", "love"})
	      == 1);
}
