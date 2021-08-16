// ! Stage 2 | Using useStaticQuery or StaticQuery API from Gatsby v2
import React from 'react';
import { css } from '@emotion/core';
import { rhythm } from '../utils/typography';
import { useStaticQuery, Link, graphql } from 'gatsby';

// ! What changed?
	// - We're now integrating a staticQuery hook in the layout component.
	// - We're querying inside a export default function.
	// - We're now rendering the data from the layout component.
	// 	- From which it should not be allowed. But doing list #1 will make it allowed.

// ! Seriously what changed?
	// - Added GraphQL Query to Render SiteTitle Metadata from Gatsby-config.JS

export default ({ children }) => {
	const data = useStaticQuery(
		graphql`
			query {
				site {
					siteMetadata {
						title
					}
				}
			}
		`
	);
	return (
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
					{data.site.siteMetadata.title}
				</h3>
			</Link>
			<Link to={`/about/`} css={css`float: right;`}>
				About
			</Link>
			{children}
		</div>
	);
};

// ! This layout is VERY different from what we have from the Third App.

// ! We reiterate the things that we did in the Third App.
// * Follow the instructions from the documentation tutorial or
// * please refer to that 'third' app for more information on how these files work.
