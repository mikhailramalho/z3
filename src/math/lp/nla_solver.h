/*++
Copyright (c) 2017 Microsoft Corporation

Module Name:

    <name>

Abstract:

    <abstract>

Author:
    Nikolaj Bjorner (nbjorner)
    Lev Nachmanson (levnach)

Revision History:


--*/
#pragma once
#include "util/vector.h"
#include "math/lp/lp_settings.h"
#include "util/rlimit.h"
#include "util/params.h"
#include "nlsat/nlsat_solver.h"
#include "math/lp/lar_solver.h"
#include "math/lp/monomial.h"
#include "math/lp/nla_core.h"
namespace nla {

// nonlinear integer incremental linear solver
class solver {
    core* m_core;
public:
    void add_monomial(lpvar v, unsigned sz, lpvar const* vs);
    
    solver(lp::lar_solver& s);
    ~solver();
    inline core * get_core() { return m_core; } 
    void push();
    void pop(unsigned scopes);
    bool need_check();
    lbool check(vector<lemma>&);
    std::ostream& display(std::ostream& out);
    bool is_monomial_var(lpvar) const;
    lp::impq get_lower_bound(lpvar j) const;
    lp::impq get_upper_bound(lpvar j) const;
    bool monomial_has_lower_bound(lpvar j) const;
    bool monomial_has_upper_bound(lpvar j) const;
};
}