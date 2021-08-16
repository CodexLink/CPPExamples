import React from "react";

// ! We reference our container that contains JSX and CSS Module.
import Container from "../components/container";
import styles from "./about-css-modules-module.css";

//console.log(styles); // ! This was supposed to output CSS Module into CSS UniqueClasses.

// ! Used as a User Tag Component Below Inside Export Default Function.

// ! THIS COMPONENT WAS USED IN ONE CASE ONLY. THEREFORE INLINED.
// * If this component however, used in multiple places. Prefer to store it components folder.

const User = props => (
    <div className={styles.user}>
        <img src={props.avatar} className={styles.avatar} alt="" />
        <div className={styles.description}>
            <h2 className={styles.username}>{props.username}</h2>
            <p className={styles.excerpt}>{props.excerpt}</p>
        </div>
    </div>
)

// ! Anything that is inside of Container Tag Scope is the argument known as { children }.
export default () => (
    <Container>
        <h1>About CSS Modules</h1>
        <p>CSS Modules are coool.</p>
        <User
            username="Jane Doe"
            avatar="https://s3.amazonaws.com/uifaces/faces/twitter/adellecharles/128.jpg"
            excerpt="I'm Jane Doe. Lorem ipsum dolor sit amet, consectetur adipisicing elit."
        />
        <User
            username="Bob Smith"
            avatar="https://s3.amazonaws.com/uifaces/faces/twitter/vladarbatov/128.jpg"
            excerpt="I'm Bob Smith, a vertically aligned type of guy. Lorem ipsum dolor sit amet, consectetur adipisicing elit."
        />
    </Container>
)

// ! In this initial tutorial. This was most likely to introduce ourselves in CSS-in-JS.
// * This tutorials only covers CSS Implementation to JS by Calling it by Class Method.

// ! I therefore, conclude that, we should go further in SCSS. After following the whole tutorial.