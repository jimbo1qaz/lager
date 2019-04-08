//
// lager - library for functional interactive c++ programs
// Copyright (C) 2017 Juan Pedro Bolivar Puente
//
// This file is part of lager.
//
// lager is free software: you can redistribute it and/or modify
// it under the terms of the MIT License, as detailed in the LICENSE
// file located at the root of this source code distribution,
// or here: <https://github.com/arximboldi/lager/blob/master/LICENSE>
//

#include <catch.hpp>

#include <lager/deps.hpp>

struct foo
{
    int x = 0;
};

struct bar
{
    const char* s = "lol";
};

TEST_CASE("basic")
{
    auto x = lager::deps<foo, bar>{foo{}, bar{}};
    CHECK(x.get<foo>().x == 0);
    CHECK(x.get<bar>().s == std::string{"lol"});
}

TEST_CASE("reference")
{
    auto f = foo{};
    auto x = lager::deps<foo&, bar>{f, bar{}};
    f.x    = 42;
    CHECK(x.get<foo>().x == 42);
    CHECK(x.get<bar>().s == std::string{"lol"});
}
