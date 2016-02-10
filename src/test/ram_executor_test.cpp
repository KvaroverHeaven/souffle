/*
 * Copyright (c) 2013-15, Oracle and/or its affiliates.
 *
 * All rights reserved.
 */

/************************************************************************
 *
 * @file type_system_test.h
 *
 * Tests souffle's type system operations.
 *
 ***********************************************************************/

#include "test.h"

#include "AstProgram.h"
#include "RamTranslator.h"
#include "RamExecutor.h"
#include "RamStatement.h"

namespace test {

    TEST(Ast, CloneAndEquals) {

        // TODO: add test for records

        // load some test program
        AstProgram program = AstProgram::parse(
            R"(
                 .number_type N
                 .decl e( a : N, b : N )
                 .decl l( a : N, b : N ) output

                 e(1,2).
                 e(2,3).
                 e(3,4).

                 l(a,b) :- e(a,b).
                 l(a,c) :- e(a,b), l(b,c).
            )"
        );

        // parse program
        EXPECT_EQ(program, program);
//        std::cout << program << "\n";

        // translate AST to RAM
        auto ram_prog = RamTranslator().translateProgram(program);
//        std::cout << *ram_prog << "\n";

        // execute RAM program
        RamEnvironment env;
        RamInterpreter executor;
        executor.getConfig().setOutputDir("-");
        executor.applyOn(*ram_prog, env);

        ASSERT_TRUE(env.hasRelation("l"));
        auto& rel = env.getRelation("l");

//        for(const auto& cur : rel) {
//            for(unsigned i=0; i<rel.getArity(); i++) {
//                std::cout << cur[i] << " ";
//            }
//            std::cout << "\n";
//        }

        EXPECT_EQ(6, rel.size());

        // done
        delete ram_prog;
    }

} // end namespace test
