#include <catch2/catch.hpp>

#include "imageOutput.hpp"

TEST_CASE("01: imageOutput class works as expected",
          "[weberRaytracing::imageOutput]") {
  // taken from the PPM example on this wikipedia page:
  // https://en.wikipedia.org/wiki/Netpbm#File_formats

  weberRaytracing::dataStructures::Image testImage = {
      {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0},},
      {{1.0, 1.0, 0.0}, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0},},
  };


  SECTION( "outputToPPM produces expected output" ) {
    auto expectedPPMString = "P3\n"
                             "3 2 1\n"
                             "1 0 0\n"
                             "0 1 0\n"
                             "0 0 1\n"
                             "1 1 0\n"
                             "1 1 1\n"
                             "0 0 0\n";

    REQUIRE(weberRaytracing::imageOutput::outputToPPM(testImage).compare(
            expectedPPMString));
  }
}
