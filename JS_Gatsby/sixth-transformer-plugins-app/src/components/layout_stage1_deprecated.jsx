// ! Stage 1 | Setting Up
import React from 'react';
import { css } from '@emotion/core';
import { Link } from 'gatsby';
import { rhythm } from '../utils/typography';

// ! THIS LAYOUT.JSX WILL BE DEPRECATED ON THE LATER STAGE.
// ! ENABLE THIS ONE FIRST BEFORE ANY OTHER SUCH.
// ! PROCEED TO LATEST LAYOUT.JSX
export default ({ children }) => (
	<div
		css={css`
			margin: 0 auto;
			max-width: 700px;
			padding: ${rhythm(2)};
			padding-top: ${rhythm(1.5)};
		`}
	>
		<Link to={`/`}>
			<h3
				css={css`
					margin-bottom: ${rhythm(2)};
					display: inline-block;
					font-style: normal;
				`}
			>
				Pandas Eating Lots
			</h3>
		</Link>
		<Link to={`/about/`} css={css`float: right;`}>
			About
		</Link>
		{children}
	</div>
);

// ! This layout is VERY different from what we have from the Third App.

// ! We reiterate the things that we did in the Third App.
// * Follow the instructions from the documentation tutorial or
// * please refer to that 'third' app for more information on how these files work.