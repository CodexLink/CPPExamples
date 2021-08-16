import Typhography from "typography";
import fairyGateTheme from "typography-theme-fairy-gates";

const typography = new Typhography(fairyGateTheme);

// ! Deconstructuring Object (?) | Needs Confirmation
// * But usually multiple non-default function declaration
export const {scale, rhythm, options} = typography;

// ! Here: export const {scale, rhythm, options} = typography;
/*
    * Could potentially be equivalent to ({typography}) => (
    *     this.scale = typography
    *     this.rhythm = typography
    *     this.options = typography
    * )

    ! Just Visual! Not Confirmed...
*/
export default typography;