import React from 'react';
import { Link } from 'gatsby'; // ! Import Links to be used by Navigation Links from Add a Site Title Section.

// ! Suggestion: This could be a candidate as another JSX Component.
// ! How? It should be a children component of a navigation bar.
const ListLink = (props) => (
	<li style={{ display: `inline-block`, marginRight: `1rem` }}>
		<Link to={props.to}>{props.children}</Link>
	</li>
);

// ! First Component Layout.
// * As the task suggest, we have to create our components
// * bit-by-bit. So here, the main purpose of our layout was to make a proper
// * Alignment / Layout for the Contacts.JS and About.JS

// ! Here the use of JSX extension is better. But still personal preference and optional.

export default ({ children }) => (
	<div style={{ margin: `3rem auto`, maxWidth: 650, padding: `0 1rem` }}>
		{ /* <h3>MySweetSite</h3> // ! Add a Site Title Starting Point on Line 13. */ }

		<header style={{ marginBottom: `1.5rem` }}> {/* // ! Add a header to be added below of the site title. */}
			<Link to="/" style={{ textShadow: `none`, backgroundImage: `none` }}>
				<h3 style={{ display: `inline` }}>MySweetSite</h3>
			</Link>
			<ul style={{ listStyle: `none`, float: `right` }}>
				<ListLink to="/">Home</ListLink>
				<ListLink to="/about/">About</ListLink>
				<ListLink to="/contact/">Contact</ListLink>
			</ul>
		</header>
		{children}
	</div>
);

// ! Why should we rename our components as JSX?
// !    Because to better know the difference between a Javascript File That Contains Functions
// !    And a Javascript File that contains HTML syntax.



// ! At this point, we're able to do the components of the following:
    // - Layout
    // - Navigation Bar (Inlined)
    // - Navigation Links (Inlined)
// * CHALLENGE: CREATE A COMPONENT OF THE FOLLOWING:
    // - Footer
    // - Header
    // - Sidebar
    // - (BONUS) Navigation Bar with Children of Title and Links | To Be Made Soon If Possibly Bored.