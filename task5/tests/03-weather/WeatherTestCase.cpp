//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(WeatherTestCase, invalid_response) {
    WeatherMock weather;
    cpr::Response response;
    response.status_code = 404;

    EXPECT_CALL(weather, Get("randomCity")).WillOnce(testing::Return(response));

    ASSERT_THROW(weather.GetResponseForCity("randomCity"), std::invalid_argument);
}

TEST(WeatherTestCase, difference_string) {
    WeatherMock weather;
    cpr::Response response1, response2;

    response1.status_code = 200;
    response2.status_code = 200;

    response1.text = "{\"list\" : [{\"main\": {\"temp\": 0}}]}";
    response2.text = "{\"list\" : [{\"main\": {\"temp\": 20}}]}";

    EXPECT_CALL(weather, Get("London")).WillOnce(testing::Return(response1));
    EXPECT_CALL(weather, Get("Sochi")).WillOnce(testing::Return(response2));

    ASSERT_EQ(weather.GetDifferenceString("London", "Sochi"), "Weather in London is colder than in Sochi by 20 degrees");
    ASSERT_EQ(weather.GetDifferenceString("Sochi", "London"), "Weather in Sochi is warmer than in London by 20 degrees");

}

TEST(WeatherTestCase, ) {
    WeatherMock weather;
    cpr::Response response;

    response.status_code = 200;

    response.text = "{\"list\" : [{\"main\": {\"temp\": -5}}]}";

    EXPECT_CALL(weather, Get("Dubki")).WillOnce(testing::Return(response));
    EXPECT_CALL(weather, Get("Bondari")).WillOnce(testing::Return(response));

    ASSERT_EQ(weather.GetTemperature("Dubki"), -5);
    ASSERT_EQ(weather.FindDiffBetweenTwoCities("Dubki", "Bondari"), 0);
    //ASSERT_EQ(weather.GetDifferenceString("Sochi", "London"), "Weather in Sochi is warmer than in London by 20 degrees");

}

TEST(WeatherTestCase, api_key) {
    WeatherMock weather;
    ASSERT_NO_THROW(weather.SetApiKey("api_key"));
}





