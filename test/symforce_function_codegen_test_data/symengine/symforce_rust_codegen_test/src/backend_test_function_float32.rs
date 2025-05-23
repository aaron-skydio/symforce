// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.rs.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

pub mod sym {

    #[allow(unused_parens)]

    ///
    /// Given input symbols `x` and `y`, return a list of expressions which provide good test coverage
    /// over symbolic functions supported by symforce.
    ///
    /// The intention is that generating this function for a given backend should provide good test
    /// coverage indicating that the printer for that backend is implemented correctly.
    ///
    /// This does not attempt to test the rest of the backend (any geo, cam, matrix, or DataBuffer use),
    /// just the printer itself.

    pub fn backend_test_function_float32(
        x: f32,
        y: f32,
        res0: Option<&mut f32>,
        res1: Option<&mut f32>,
        res2: Option<&mut f32>,
        res3: Option<&mut f32>,
        res4: Option<&mut f32>,
        res5: Option<&mut f32>,
        res6: Option<&mut f32>,
        res7: Option<&mut f32>,
        res8: Option<&mut f32>,
        res9: Option<&mut f32>,
        res10: Option<&mut f32>,
        res11: Option<&mut f32>,
        res12: Option<&mut f32>,
        res13: Option<&mut f32>,
        res14: Option<&mut f32>,
        res15: Option<&mut f32>,
        res16: Option<&mut f32>,
        res17: Option<&mut f32>,
        res18: Option<&mut f32>,
        res19: Option<&mut f32>,
        res20: Option<&mut f32>,
        res21: Option<&mut f32>,
        res22: Option<&mut f32>,
        res23: Option<&mut f32>,
        res24: Option<&mut f32>,
        res25: Option<&mut f32>,
        res26: Option<&mut f32>,
        res27: Option<&mut f32>,
        res28: Option<&mut f32>,
        res29: Option<&mut f32>,
        res30: Option<&mut f32>,
        res31: Option<&mut f32>,
        res32: Option<&mut f32>,
        res33: Option<&mut f32>,
        res34: Option<&mut f32>,
        res35: Option<&mut f32>,
        res36: Option<&mut f32>,
        res37: Option<&mut f32>,
        res38: Option<&mut f32>,
        res39: Option<&mut f32>,
        res40: Option<&mut f32>,
        res41: Option<&mut f32>,
        res42: Option<&mut f32>,
        res43: Option<&mut f32>,
        res44: Option<&mut f32>,
        res45: Option<&mut f32>,
        res46: Option<&mut f32>,
        res47: Option<&mut f32>,
        res48: Option<&mut f32>,
        res49: Option<&mut f32>,
        res50: Option<&mut f32>,
        res51: Option<&mut f32>,
        res52: Option<&mut f32>,
        res53: Option<&mut f32>,
        res54: Option<&mut f32>,
        res55: Option<&mut f32>,
    ) -> () {
        // Total ops: 58

        // Intermediate terms (5)
        let _tmp0: f32 = 2_f32.ln();
        let _tmp1: f32 = core::f32::consts::PI.powf((-1_f32 / 1_f32));
        let _tmp2: f32 = 2_f32.powf((1_f32 / 2_f32));
        let _tmp3: f32 = x.powf((1_f32 / 2_f32));
        let _tmp4: f32 = x + y;

        // Output terms (56)
        if let Some(res0) = res0 {
            *res0 = 0.0;
        }

        if let Some(res1) = res1 {
            *res1 = 1_f32;
        }

        if let Some(res2) = res2 {
            *res2 = (1_f32 / 2_f32);
        }

        if let Some(res3) = res3 {
            *res3 = 1.60000000000000_f32;
        }

        if let Some(res4) = res4 {
            *res4 = (11_f32 / 52_f32);
        }

        if let Some(res5) = res5 {
            *res5 = core::f32::consts::E;
        }

        if let Some(res6) = res6 {
            *res6 = _tmp0.powf((-1_f32 / 1_f32));
        }

        if let Some(res7) = res7 {
            *res7 = _tmp0;
        }

        if let Some(res8) = res8 {
            *res8 = 10_f32.ln();
        }

        if let Some(res9) = res9 {
            *res9 = core::f32::consts::PI;
        }

        if let Some(res10) = res10 {
            *res10 = (1_f32 / 2_f32) * core::f32::consts::PI;
        }

        if let Some(res11) = res11 {
            *res11 = (1_f32 / 4_f32) * core::f32::consts::PI;
        }

        if let Some(res12) = res12 {
            *res12 = _tmp1;
        }

        if let Some(res13) = res13 {
            *res13 = 2_f32 * _tmp1;
        }

        if let Some(res14) = res14 {
            *res14 = 2_f32 / core::f32::consts::PI.powf((1_f32 / 2_f32));
        }

        if let Some(res15) = res15 {
            *res15 = _tmp2;
        }

        if let Some(res16) = res16 {
            *res16 = (1_f32 / 2_f32) * _tmp2;
        }

        if let Some(res17) = res17 {
            *res17 = x.abs();
        }

        if let Some(res18) = res18 {
            *res18 = x.sin();
        }

        if let Some(res19) = res19 {
            *res19 = x.cos();
        }

        if let Some(res20) = res20 {
            *res20 = x.tan();
        }

        if let Some(res21) = res21 {
            *res21 = x.asin();
        }

        if let Some(res22) = res22 {
            *res22 = x.acos();
        }

        if let Some(res23) = res23 {
            *res23 = x.atan();
        }

        if let Some(res24) = res24 {
            *res24 = x.exp();
        }

        if let Some(res25) = res25 {
            *res25 = x.ln();
        }

        if let Some(res26) = res26 {
            *res26 = x.sinh();
        }

        if let Some(res27) = res27 {
            *res27 = x.cosh();
        }

        if let Some(res28) = res28 {
            *res28 = x.tanh();
        }

        if let Some(res29) = res29 {
            *res29 = x.floor();
        }

        if let Some(res30) = res30 {
            *res30 = x.ceil();
        }

        if let Some(res31) = res31 {
            *res31 = _tmp3;
        }

        if let Some(res32) = res32 {
            *res32 = x.asinh();
        }

        if let Some(res33) = res33 {
            *res33 = x.acosh();
        }

        if let Some(res34) = res34 {
            *res34 = x.atanh();
        }

        if let Some(res35) = res35 {
            *res35 = x - 5.5_f32 * (0.181818181818182_f32 * x).floor();
        }

        if let Some(res36) = res36 {
            *res36 = x + 1_f32;
        }

        if let Some(res37) = res37 {
            *res37 = 2_f32 * x;
        }

        if let Some(res38) = res38 {
            *res38 = x.powf((2_f32 / 1_f32));
        }

        if let Some(res39) = res39 {
            *res39 = x.powf((3_f32 / 1_f32));
        }

        if let Some(res40) = res40 {
            *res40 = x.powf((4_f32 / 1_f32));
        }

        if let Some(res41) = res41 {
            *res41 = x.powf((5_f32 / 1_f32));
        }

        if let Some(res42) = res42 {
            *res42 = _tmp3;
        }

        if let Some(res43) = res43 {
            *res43 = x.powf((3_f32 / 2_f32));
        }

        if let Some(res44) = res44 {
            *res44 =
                (1_f32 / 2_f32) * (if (x == 0.0) { 0.0 } else { (x).signum() }) + (1_f32 / 2_f32);
        }

        if let Some(res45) = res45 {
            *res45 = x.signum();
        }

        if let Some(res46) = res46 {
            *res46 = x.atan2(y);
        }

        if let Some(res47) = res47 {
            *res47 = x.max(y);
        }

        if let Some(res48) = res48 {
            *res48 = x.min(y);
        }

        if let Some(res49) = res49 {
            *res49 = x - y * (x / y).floor();
        }

        if let Some(res50) = res50 {
            *res50 = _tmp4;
        }

        if let Some(res51) = res51 {
            *res51 = x * y;
        }

        if let Some(res52) = res52 {
            *res52 = x.powf(y);
        }

        if let Some(res53) = res53 {
            *res53 = _tmp4.powf((2_f32 / 1_f32));
        }

        if let Some(res54) = res54 {
            *res54 = _tmp4.powf((3_f32 / 1_f32));
        }

        if let Some(res55) = res55 {
            *res55 = x.copysign(y);
        }
    }
} // mod sym
