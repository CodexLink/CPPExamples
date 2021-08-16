// ! We consider this file as JS.
// ! Since we're doing HTML in JS. I would like to declare it as a
// ! JSX. Which stands for Javascript XML.
import React from 'react';
import containerStyles from './container.module.css';

// ! Minified
export default ({ children }) => <div className={containerStyles.container}>{children}</div>;

// ! Here in this JSX. We're trying to do styling by referencing to the CSS Stylesheet.
// * The intention was to try to do some class styled component calling.
// ! Instead of calling the CSS stylesheet names, we do import it and do different method of calling styles.
// * For instance <div className="container">, we do <div className={containerImportName.<styleSelector>}>